#pragma once

typedef void* HANDLE;

ref class SerialPortManager
{
public: static bool writeSerialPort(HANDLE serialHandle, System::String^ content, char messageType, int messageLength);
public: static int readSerialPort(HANDLE serialHandle, System::String^% receivedData, bool% shouldContinue, System::String^ terminator);
public:
	static HANDLE setupConnection(HANDLE& serialHandle);
};

<<<<<<< HEAD
enum MessageTypesEnum : int {
	PING = 0,
	NORMAL_MESSAGE = 1,
	MESSAGE_ACKNOWLEDGEMENT = 2,
	PING_ACKNOWLEDGEMENT = 3
};
=======
>>>>>>> 6f038e9d32a2e609970c9e5c21c240b05df17f59
