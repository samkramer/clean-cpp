#ifndef SWITCH_H_
#define SWITCH_H_

#include "switchable.h"

class Switch
{
public:
	Switch(Switchable& switchable);
	~Switch() = default;

	void toggle();

private:
	Switchable& switchable;
	bool state;
};

#endif /* SWITCH_H_ */
