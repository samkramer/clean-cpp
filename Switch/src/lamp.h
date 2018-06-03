#ifndef LAMP_H_
#define LAMP_H_

#include "switchable.h"
#include <iostream>

class Lamp : public Switchable
{
public:
	Lamp() = default;
	~Lamp() = default;

	void on() override
	{
		std::cout << "Lamp is ON" << std::endl;
	}

	void off() override
	{
		std::cout << "Lamp is OFF" << std::endl;
	}
};

#endif /* LAMP_H_ */
