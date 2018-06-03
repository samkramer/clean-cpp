#ifndef HELLOWORLDOUTPUTCOMMAND_H_
#define HELLOWORLDOUTPUTCOMMAND_H_

#include "command.h"
#include <iostream>

class HelloWorldOutputCommand : public Command
{
public:
	virtual void execute() override {
		std::cout << "Hello World!\n";
	}
};


#endif /* HELLOWORLDOUTPUTCOMMAND_H_ */
