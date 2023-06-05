#include "pch.h"
#include "SerialPortManager.h"

#include <msclr/marshal_cppstd.h>
#include "Endpoint.h"
#include "ConfigurationForm.h"
#include "EndpointConfig.h"

using namespace System;
using namespace System::IO::Ports;

// to debug if works properly
// assuming terminator is accounted for
// messageLegth = length(message) + length(terminator)
bool SerialPortManager::writeSerialPort(HANDLE serialHandle, System::String^ content, char messageType, int messageLength)
{
	unsigned long numberOfBytesWritten = 0;
	unsigned long numberOfBytesToWrite = content->Length;

	bool status = true;

	char headerBuffer[sizeof(char) + sizeof(int)];
	headerBuffer[0] = messageType;
	memcpy(headerBuffer + 1, &messageLength, sizeof(int));  // Consider lower byte only

	if (!WriteFile(serialHandle, headerBuffer, sizeof(char) + sizeof(int), &numberOfBytesWritten, NULL))
		return false;

	pin_ptr<const System::Char> pinnedContent = PtrToStringChars(content);  // Get pinned pointer to content data

	numberOfBytesWritten = 0;
	while (numberOfBytesToWrite > numberOfBytesWritten) {
		int bufferLength = numberOfBytesToWrite - numberOfBytesWritten;
		if (bufferLength > 512) {
			bufferLength = 512;
		}

		status = WriteFile(serialHandle, pinnedContent + numberOfBytesWritten, bufferLength, &numberOfBytesWritten, NULL) != 0;

		if (!status) {
			return false;
		}
	}

	return true;
}

int SerialPortManager::readSerialPort(HANDLE serialHandle, System::String^% receivedData, bool% shouldContinue, System::String^ terminator)
{
	const int bufferSize = 512;
	char buffer[bufferSize];
	DWORD bytesRead = 0;

	bool headerRead = false;
	char headerBuffer[5] = { 0 }; // Array to store the header bytes

	while (shouldContinue) {
		// Read the data
		if (ReadFile(serialHandle, buffer, bufferSize, &bytesRead, NULL) != 0 && bytesRead > 0) {
			// Process the received data
			if (!headerRead) {
				// Assuming the header size is fixed to 5 bytes
				if (bytesRead >= 5) {
					// Copy the header bytes to the header buffer
					memcpy(headerBuffer, buffer, 5);
					if (headerBuffer[0] == 0) {
						return headerBuffer[0];
					}

					headerRead = true;
				}

				// Append the remaining data (after the header) to the receivedData string
				if (bytesRead > 5) {
					std::string temp(buffer + 5, bytesRead - 5);
					receivedData += gcnew System::String(temp.c_str());
				}

			}
			else {
				std::string temp(buffer, bytesRead);
				receivedData += gcnew System::String(temp.c_str());
			}

			if (receivedData != nullptr && (terminator->Length == 0 || receivedData->Contains(terminator))) {
				// Stop reading if the condition is met
				return headerBuffer[0];
			}
		}
		else {
			// Handle timeout or other read errors
			return -1;
		}
	}
}

HANDLE SerialPortManager::setupConnection(HANDLE& serialHandle) {
	CustomPortConfiguration^ portConfiguration = CppCLRWinformsProjekt::ConfigurationForm::portConfiguration;

	EndpointConfiguration endpoint;
	std::string portName = portConfiguration->getPortName();
	std::wstring portNameWstr(portName.begin(), portName.end());
	endpoint.portName = (LPCTSTR)(portNameWstr.c_str());

	DCB portConfigurationHandle = { 0 };
	portConfigurationHandle.DCBlength = sizeof(portConfigurationHandle);

	COMMPROP comProperties = { 0 };
	comProperties.wPacketLength = sizeof(COMMPROP);
	comProperties.dwProvSpec1 = COMMPROP_INITIALIZED;
	memset(&comProperties, 0, sizeof(COMMPROP));

	serialHandle = CreateFile(endpoint.portName, endpoint.portAccess, endpoint.shareMode, endpoint.securityAttributes, endpoint.creationMethod,
		endpoint.flagAndAttributes, endpoint.templateFileHandle);

	if (serialHandle == INVALID_HANDLE_VALUE) {
		/*
			IE_BADID –1 Niew³aœciwa identyfikacja urz¹dzenia
			IE_BAUDRATE –12 B³êdnie okreœlona szybkoœæ transmisji
			IE_BYTESIZE –11 B³êdnie okreœlona liczba bitów danych
			IE_DEFAULT –5 Niew³aœciwie okreœlone parametry domyœlne urz¹dzenia
			IE_HARDWARE –10 Odbiornik jest zablokowany
			IE_MEMORY –4 Niew³aœciwie ustalony rozmiar buforów
			IE_NOPEN –3 Urz¹dzenie nie jest otwarte do transmisji
			IE_OPEN –2 Urz¹dzenie pozostaje otwarte
		*/
		System::Windows::Forms::MessageBox::Show("B³¹d przy otwieraniu portu", "B³¹d",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		CloseHandle(serialHandle);
		return (HANDLE)-1;
	}

	if (!GetCommState(serialHandle, &portConfigurationHandle)) {
		System::Windows::Forms::MessageBox::Show("Nie mo¿na odczytaæ parametrów portu", "B³¹d",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		CloseHandle(serialHandle);
		return (HANDLE)-1;
	}

	portConfigurationHandle.BaudRate = portConfiguration->baudRate;
	portConfigurationHandle.ByteSize = portConfiguration->bitCount;

	if (portConfiguration->stopBitCount == 1) {
		portConfigurationHandle.StopBits = ONESTOPBIT;
	}
	else {
		portConfigurationHandle.StopBits = TWOSTOPBITS;
	}

	switch (portConfiguration->dataControlType)
	{
	case 'N':
		portConfigurationHandle.Parity = NOPARITY;
		break;
	case 'O':
		portConfigurationHandle.Parity = ODDPARITY;
		break;
	case 'E':
		portConfigurationHandle.Parity == EVENPARITY;
		break;
	default:
		portConfigurationHandle.Parity = NOPARITY;
		break;
	}

	portConfigurationHandle.fParity = portConfigurationHandle.Parity != NOPARITY;
	portConfigurationHandle.fDtrControl = 1;

	if (!SetCommState(serialHandle, &portConfigurationHandle)) {
		DWORD error = GetLastError();
		System::Windows::Forms::MessageBox::Show("Nie mo¿na zapisaæ parametrów portu", "B³¹d",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		CloseHandle(serialHandle);
		return (HANDLE)-1;
	}

	// Set timeouts
	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = MAXDWORD;      // Allow immediate return for read operations
	timeouts.ReadTotalTimeoutMultiplier = 0;      // Disable additional timeout based on bytes to read
	timeouts.ReadTotalTimeoutConstant = 100;      // Set a read timeout of 100 milliseconds
	timeouts.WriteTotalTimeoutMultiplier = 0;     // Disable additional timeout based on bytes to write
	timeouts.WriteTotalTimeoutConstant = 0;       // Disable constant timeout for write operations

	if (!SetCommTimeouts(serialHandle, &timeouts)) {
		System::Windows::Forms::MessageBox::Show("Nie uda³o siê ustawiæ timeoutów", "B³¹d",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		CloseHandle(serialHandle);
		return (HANDLE)-1;
	}

	if (!GetCommProperties(serialHandle, &comProperties)) {
		System::Windows::Forms::MessageBox::Show("Nie uda³o siê odczytaæ parametrów portu komunikacyjnego COM", "B³¹d",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		CloseHandle(serialHandle);
		return (HANDLE)-1;
	}

	// connection should now be established
	return serialHandle;
}