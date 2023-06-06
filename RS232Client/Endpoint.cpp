#include "pch.h"
#include "Endpoint.h"
#include <windows.h>
#include <math.h>
#include <atlstr.h>
#include "ConfigurationForm.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <thread>
#include "EndpointConfig.h"


std::string CustomPortConfiguration::getPortName() {
	return  msclr::interop::marshal_as<std::string>(portName->ToString());
}

std::vector<std::string> EndpointManager::listCOMPorts() {
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

void EndpointManager::readCOMPortConfiguration(CustomPortConfiguration^ port) {
	EndpointConfiguration defaultEndpointConfiguration;
	std::string portName = port->getPortName();
	std::wstring portNameWstr(portName.begin(), portName.end());
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

	port->baudRate = portConfigurationHandle.BaudRate;
	port->bitCount = portConfigurationHandle.ByteSize;
	
	switch (portConfigurationHandle.StopBits)
	{
	case TWOSTOPBITS:
		port->stopBitCount = 2;
		break;
	case ONESTOPBIT:
	default:
		port->stopBitCount = 1;
		break;
	}

	if (portConfigurationHandle.fParity) {
		switch (portConfigurationHandle.Parity)
		{
		case EVENPARITY:
			port->dataControlType = 'E';
			break;
		case ODDPARITY:
			port->dataControlType = 'O';
		case NOPARITY:
		default:
			port->dataControlType = 'N';
			break;
		}
	}
	else {
		port->dataControlType = 'N';
	}

	CloseHandle(serialHandle);
}