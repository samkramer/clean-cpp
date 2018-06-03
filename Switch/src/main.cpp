#include <iostream>
#include "switch.h"
#include "lamp.h"

int main()
{
	Lamp lamp;

	Switch s(lamp);
	s.toggle();
	s.toggle();
}
