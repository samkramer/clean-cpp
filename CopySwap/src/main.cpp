#include <iostream>
#include "clazz.h"

int main()
{
	Clazz c1 {8, 'B'};
	Clazz c2 {c1};
	Clazz c3;
	c3 = c2;

	std::cout << "c1: " << c1 << std::endl;
	std::cout << "c2: " << c2 << std::endl;
	std::cout << "c3: " << c3 << std::endl;
}
