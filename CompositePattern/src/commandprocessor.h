#ifndef COMMANDPROCESSOR_H_
#define COMMANDPROCESSOR_H_

#include "command.h"
#include <iostream>
#include <memory>
#include <stack>

class CommandProcessor
{
public:
	void execute(const CommandPtr& command) {
		command->execute();
		commandHistory.push(command);
	}

	void undoLastCommand() {
		if (commandHistory.empty()) {
			std::cout << "[WARN] No commands in history" << std::endl;
			return;
		}

		commandHistory.top()->undo();
		commandHistory.pop();
	}

private:
	std::stack<std::shared_ptr<Revertable>> commandHistory;
};

#endif /* COMMANDPROCESSOR_H_ */
