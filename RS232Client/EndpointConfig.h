#pragma once
#include <windows.h>
#include <tchar.h>


struct EndpointConfiguration {
	LPCTSTR portName = _T("COM4");
	DWORD portAccess = GENERIC_READ | GENERIC_WRITE;
	DWORD creationMethod = OPEN_EXISTING;
	DWORD shareMode = 0;
	LPSECURITY_ATTRIBUTES securityAttributes = nullptr;
	DWORD flagAndAttributes = 0;
	HANDLE templateFileHandle = nullptr;
};