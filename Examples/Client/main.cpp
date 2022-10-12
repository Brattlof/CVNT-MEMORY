#include <iostream>

#include <External.h>

int main(void)
{
	External::Init();

	External& rExternal = External::GetInstance();

	External::Deinit();

	return 0x0;
}