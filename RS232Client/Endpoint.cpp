#include "pch.h"
#include "Endpoint.h"
#include <windows.h>
#include <atlstr.h>

typedef struct EndpointConfiguration {
	LPCTSTR portName = _T("COM4");
	DWORD portAccess = GENERIC_READ | GENERIC_WRITE; // write to port or read - full duplex
	DWORD creationMethod = OPEN_EXISTING;
	DWORD shareMode = 0;
	LPSECURITY_ATTRIBUTES securityAttributes = NULL;
	DWORD flagAndAttributes = 0;
	HANDLE templateFileHandle = NULL;
};

std::vector<std::string> listCOMPorts() {
	EndpointConfiguration defaultEndpointConfiguration;
	HANDLE serialHandle;
	std::vector<std::string> comPorts;

	for (int i = 0; i < 255; i++) {
		std::string portName = std::string("COM") + std::to_string(i);
		std::wstring portNameWstr(portName.begin(), portName.end());
		defaultEndpointConfiguration.portName = (LPCTSTR)(portNameWstr.c_str());

		serialHandle = CreateFile(defaultEndpointConfiguration.portName, defaultEndpointConfiguration.portAccess, defaultEndpointConfiguration.shareMode,
			defaultEndpointConfiguration.securityAttributes, defaultEndpointConfiguration.creationMethod,
			defaultEndpointConfiguration.flagAndAttributes, defaultEndpointConfiguration.templateFileHandle);

		if (serialHandle != INVALID_HANDLE_VALUE) {
			comPorts.push_back(portName);
		}

		CloseHandle(serialHandle);
	}

	return comPorts;
}

void readCOMPortConfiguration(CustomPortConfiguration& port) {
	EndpointConfiguration defaultEndpointConfiguration;
	std::wstring portNameWstr(port.portName.begin(), port.portName.end());
	defaultEndpointConfiguration.portName = (LPCTSTR)(portNameWstr.c_str());

	HANDLE serialHandle = CreateFile(defaultEndpointConfiguration.portName, defaultEndpointConfiguration.portAccess, defaultEndpointConfiguration.shareMode,
		defaultEndpointConfiguration.securityAttributes, defaultEndpointConfiguration.creationMethod,
		defaultEndpointConfiguration.flagAndAttributes, defaultEndpointConfiguration.templateFileHandle);

	if (serialHandle == INVALID_HANDLE_VALUE) {
		return;
	}

	DCB portConfigurationHandle = { 0 };
	portConfigurationHandle.DCBlength = sizeof(portConfigurationHandle);

	if (!GetCommState(serialHandle, &portConfigurationHandle)) {
		return;
	}

	port.baudRate = portConfigurationHandle.BaudRate;
	port.bitCount = portConfigurationHandle.ByteSize;
	
	switch (portConfigurationHandle.StopBits)
	{
	case TWOSTOPBITS:
		port.stopBitCount = 2;
		break;
	case ONESTOPBIT:
	default:
		port.stopBitCount = 1;
		break;
	}

	if (portConfigurationHandle.fParity) {
		switch (portConfigurationHandle.Parity)
		{
		case EVENPARITY:
			port.dataControlType = 'E';
			break;
		case ODDPARITY:
			port.dataControlType = 'O';
		case NOPARITY:
		default:
			port.dataControlType = 'N';
			break;
		}
	}
	else {
		port.dataControlType = 'N';
	}

	CloseHandle(serialHandle);
}


// to debug if works properly
bool writeSerialPort(HANDLE serialHandle, std::string content, char messageType, int messageLength)
{
	unsigned long numberOfBytesWritten = 0;
	unsigned long numberOfBytesToWrite = content.length();

	bool status = true;

	char* headerBuffer = new char[sizeof(char) + sizeof(int)];
	headerBuffer[0] = messageType;
	headerBuffer[1] = messageLength;
	if (!WriteFile(serialHandle, headerBuffer, sizeof(char) + sizeof(int), &numberOfBytesWritten, NULL))
		return false;

	while (numberOfBytesToWrite > numberOfBytesWritten) {
		if (numberOfBytesToWrite + 512 >= numberOfBytesWritten) {
			int buffer_length = numberOfBytesToWrite - numberOfBytesWritten;
			const char* buffer = content.substr(numberOfBytesWritten, buffer_length).c_str();
			status = WriteFile(serialHandle, buffer, buffer_length, &numberOfBytesWritten, NULL) == 0;
		}
		else {
			const char* buffer = content.substr(numberOfBytesWritten, 512).c_str();
			status = WriteFile(serialHandle, buffer, 512, &numberOfBytesWritten, NULL) == 0;
		}

		if (!status) {
			return false;
		}
		numberOfBytesWritten += 512;
	}

	return true;
}