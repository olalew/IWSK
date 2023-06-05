#pragma once

typedef void* HANDLE;

ref class SerialPortManager
{
public: static bool writeSerialPort(HANDLE serialHandle, System::String^ content, char messageType, int messageLength);
public: static bool readSerialPort(HANDLE serialHandle, System::String^% receivedData, bool% shouldContinue, System::String^ terminator);
public:
	static HANDLE setupConnection(HANDLE& serialHandle);
};

