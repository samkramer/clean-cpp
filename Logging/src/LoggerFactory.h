#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include "StandardOutputLogger.h"
#include "FilesystemLogger.h"
#include "BoostTrivialLogAdapter.h"

#include <fstream>
#include <string>

class LoggerFactory
{
private:
	enum class OutputTarget
	{
		STDOUT, FILE, BOOST
	};

public:
	static Logger create(const std::string& configurationFileName) {
		std::string configurationFileContent = readConfigurationFile(configurationFileName);
		OutputTarget outputTarget = evaluateConfiguration(configurationFileName);
		return createLogger(outputTarget);
	}

private:
	static std::string readConfigurationFile(const std::string& configurationFileName) {
		std::ifstream filestream(configurationFileName);
		return std::string(std::istreambuf_iterator<char>(filestream),
				std::istreambuf_iterator<char>());
	}

	static OutputTarget evaluateConfiguration(const std::string& configurationFileContent) {
		// TODO Evaluate content of configuration file
		return OutputTarget::BOOST;
	}

	static Logger createLogger(OutputTarget outputTarget) {
		std::string fileLogPath("/temp/customer_log.txt");

		switch (outputTarget) {
		case OutputTarget::FILE:
			return std::make_shared<FilesystemLogger>(fileLogPath);
		case OutputTarget::STDOUT:
			return std::make_shared<StandardOutputLogger>();
		case OutputTarget::BOOST:
			return std::make_shared<BoostTrivialLogAdapter>();
		default:
			return std::make_shared<StandardOutputLogger>();
		}
	}
};

#endif /* LOGGERFACTORY_H_ */
