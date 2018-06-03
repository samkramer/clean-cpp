#ifndef STANDARDOUTPUTLOGGER_H_
#define STANDARDOUTPUTLOGGER_H_

#include "LoggingFacility.h"

class StandardOutputLogger : public LoggingFacility
{
public:
	virtual void writeInfoEntry(std::string_view entry) override;
	virtual void writeWarnEntry(std::string_view entry) override;
	virtual void writeErrorEntry(std::string_view entry) override;
};

#endif /* STANDARDOUTPUTLOGGER_H_ */
