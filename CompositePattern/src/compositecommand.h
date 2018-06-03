#ifndef COMPOSITECOMMAND_H_
#define COMPOSITECOMMAND_H_

#include <vector>
#include "command.h"

class CompositeCommand : public UndoableCommand
{
public:
	void addCommand(CommandPtr command) {
		commands.push_back(command);
	}

	virtual void execute() override {
		for (const auto& command : commands) {
			command->execute();
		}
	}

	virtual void undo() override {
		for (const auto& command : commands) {
			command->undo();
		}
	}

private:
	std::vector<CommandPtr> commands;
};

#endif /* COMPOSITECOMMAND_H_ */
