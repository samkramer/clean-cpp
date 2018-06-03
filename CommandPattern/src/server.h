#ifndef SERVER_H_
#define SERVER_H_

#include "command.h"

class Server
{
public:
	void acceptCommand(const CommandPtr& command)
	{
		command->execute();
	}
};

#endif /* SERVER_H_ */
