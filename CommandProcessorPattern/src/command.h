#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

class Revertable
{
public:
	virtual ~Revertable() = default;
	virtual void undo() = 0;

};

class UndoableCommand : public Command, public Revertable { };

using CommandPtr = std::shared_ptr<Command>;
using UndoableCommandPtr = std::shared_ptr<UndoableCommand>;

#endif /* COMMAND_H_ */
