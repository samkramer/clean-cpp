#ifndef WAITCOMMAND_H_
#define WAITCOMMAND_H_

#include "command.h"
#include <iostream>
#include <cstdint>
#include <chrono>
#include <thread>

class WaitCommand : public Command
{
public:
	explicit WaitCommand(const uint32_t durationMilliseconds) noexcept
	: durationMilliseconds{durationMilliseconds} { };

	virtual void execute() override
	{
		std::cout << "[INFO] Sleeping for " << durationMilliseconds << " milliseconds" << std::endl;

		std::chrono::milliseconds duration(durationMilliseconds);
		std::this_thread::sleep_for(duration);
	}

private:
	uint32_t durationMilliseconds;
};

#endif /* WAITCOMMAND_H_ */
