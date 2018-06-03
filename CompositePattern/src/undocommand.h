#ifndef UNDOCOMMAND_H_
#define UNDOCOMMAND_H_

#include "command.h"
#include "commandprocessor.h"

class UndoCommand : public UndoableCommand
{
public:
	explicit UndoCommand(CommandProcessor& receiver)
	: receiver(receiver) {}

	virtual void execute() override {
		receiver.undoLastCommand();
	}

	virtual void undo() override {
		// Blank -- undo should not be undone.
	}

private:
	CommandProcessor& receiver;
};

#endif /* UNDOCOMMAND_H_ */
