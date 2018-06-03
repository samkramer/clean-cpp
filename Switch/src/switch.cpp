#include "switch.h"

Switch::Switch(Switchable& switchable)
  : switchable(switchable)
  , state(false)
{
	// empty body
}

void Switch::toggle()
{
	if (state)
	{
		state = false;
		switchable.off();
	}
	else
	{
		state = true;
		switchable.on();
	}
}
