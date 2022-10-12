#ifndef __EXTERNAL_H__
#define __EXTERNAL_H__

#include "Singleton.h"

#include <windows.h>
#include <TlHelp32.h>

class External : public Singleton<External>
{
public:
	~External() { if (m_ProcessHandle != NULL) CloseHandle(m_ProcessHandle); }

	bool SetProcess(const char* process_exe_name);

	DWORD FindProcessId(const char* process_exe_name);

private:
	DWORD m_ProcessId = 0x0;
	HANDLE m_ProcessHandle = NULL;
};

#endif