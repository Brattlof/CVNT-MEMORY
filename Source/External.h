#ifndef __EXTERNAL_H__
#define __EXTERNAL_H__

#include "Singleton.h"

#include <windows.h>
#include <TlHelp32.h>

class External : public Singleton<External>
{
public:
	~External() { if (m_ProcessHandle) CloseHandle(m_ProcessHandle); }

	bool SetProcess(const char* process_exe_name);

	template <class T>
	T Read(const DWORD& address)
	{
		T Out = { };
		ReadProcessMemory(m_ProcessHandle, reinterpret_cast<PVOID>(address), &Out, sizeof(T), nullptr);
		return Out;
	}

	PROCESSENTRY32 FindProcess(const char* process_exe_name);
	MODULEENTRY32  FindModule(const char* module_name);
private:
	DWORD m_ProcessId = 0x0;
	HANDLE m_ProcessHandle = NULL;
};

#endif