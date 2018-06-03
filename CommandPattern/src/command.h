#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

using CommandPtr = std::shared_ptr<Command>;

#endif /* COMMAND_H_ */
