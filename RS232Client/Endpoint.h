#pragma once

#include <tchar.h>
#include <vector>
#include <string>

class CustomPortConfiguration {
	
public:
	std::string portName;
	int baudRate;
	int bitCount;
	char dataControlType;
	int stopBitCount;
};

std::vector<std::string> listCOMPorts();

void readCOMPortConfiguration(CustomPortConfiguration& port);