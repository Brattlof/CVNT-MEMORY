#include <iostream>

#include <External.h>

int main(void)
{
	External::Init();

	External::GetInstance().SetProcess("notepad.exe");

	External::Deinit();

	return 0x0;
}