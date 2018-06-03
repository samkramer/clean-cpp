#ifndef CLIENT_H_
#define CLIENT_H_

#include "server.h"
#include "helloworldoutputcommand.h"
#include "waitcommand.h"

class Client
{
public:
	void run()
	{
		Server server;

		const uint32_t SERVER_DELAY_TIMESPAN {2000U};
		CommandPtr waitCmd = std::make_shared<WaitCommand>(SERVER_DELAY_TIMESPAN);
		server.acceptCommand(waitCmd);

		CommandPtr helloCmd = std::make_shared<HelloWorldOutputCommand>();
		server.acceptCommand(helloCmd);
	}
};

#endif /* CLIENT_H_ */
