#include <iostream>

#include <External.h>

int main(void)
{
	External::Init();

	External& rExternal = External::GetInstance();

	if (rExternal.SetProcess("notepad.exe"))
	{
		DWORD temp = rExternal.FindProcess("notepad.exe").th32ParentProcessID;
		std::cout << temp;
	}

	External::Deinit();

	return 0x0;
}