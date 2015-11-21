#include <iostream>
#include "shapefil.h"
#include "Resources.h"

int main(int arc, char* argv[])
{
	std::cout << "Hello World" << std::endl;	
	std::cout << Resources::GetPath("Shaders\\test.frag") << std::endl;
	return 0;
}