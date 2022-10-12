#include "External.h"

#include <iostream>

bool External::SetProcess(const char* process_exe_name)
{
	if (m_ProcessHandle) CloseHandle(m_ProcessHandle);

	if (GetInstance().m_ProcessId = FindProcessId(process_exe_name)) 
		return m_ProcessHandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, m_ProcessId);

	return false;
}

DWORD External::FindProcessId(const char* process_exe_name)
{
	HANDLE SnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0x0);

	PROCESSENTRY32 ProcessEntry = { };
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);

	for (Process32First(SnapshotHandle, &ProcessEntry); Process32Next(SnapshotHandle, &ProcessEntry);)
	{
		if (!strcmp(ProcessEntry.szExeFile, process_exe_name))
		{
			CloseHandle(SnapshotHandle);
			return ProcessEntry.th32ProcessID;
		}
	}

	CloseHandle(SnapshotHandle);
	return 0x0;
}