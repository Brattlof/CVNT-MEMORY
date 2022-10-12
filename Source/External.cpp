#include "External.h"

#include <iostream>

DWORD External::FindProcessId(const char* process_name)
{
	HANDLE SnapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0x0);

	PROCESSENTRY32 ProcessEntry = { };
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);

	for (Process32First(SnapshotHandle, &ProcessEntry); Process32Next(SnapshotHandle, &ProcessEntry);)
	{
		if (!strcmp(ProcessEntry.szExeFile, process_name))
		{
			CloseHandle(SnapshotHandle);
			return ProcessEntry.th32ProcessID;
		}
	}

	CloseHandle(SnapshotHandle);
	return 0x0;
}