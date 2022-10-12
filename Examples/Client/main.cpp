#include <iostream>

#include <External.h>

int main(void)
{
	std::cout << External::GetInstance().FindProcessId("notepad.exe");

	return 0x0;
}