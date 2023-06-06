#pragma once

#include <tchar.h>
#include <vector>
#include <string>

ref class CustomPortConfiguration {
	
public:
	System::String^ portName;
	System::Int32 baudRate;
	System::Int32 bitCount;
	System::Char dataControlType;
	System::Int32 stopBitCount;

	CustomPortConfiguration() {}

	// Copy constructor
	CustomPortConfiguration(const CustomPortConfiguration% other) {
		portName = other.portName;
		baudRate = other.baudRate;
		bitCount = other.bitCount;
		dataControlType = other.dataControlType;
		stopBitCount = other.stopBitCount;
	}

	std::string getPortName();
};


ref class EndpointManager
{
public: static std::vector<std::string> listCOMPorts();
public: static void readCOMPortConfiguration(CustomPortConfiguration^ port);
};