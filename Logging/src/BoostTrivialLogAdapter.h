#ifndef BOOSTTRIVIALLOGADAPTER_H_
#define BOOSTTRIVIALLOGADAPTER_H_

#include "LoggingFacility.h"

class BoostTrivialLogAdapter : public LoggingFacility
{
public:
	BoostTrivialLogAdapter();
	virtual ~BoostTrivialLogAdapter() = default;

	virtual void writeInfoEntry(std::string_view entry) override;
	virtual void writeWarnEntry(std::string_view entry) override;
	virtual void writeErrorEntry(std::string_view entry) override;
};

#endif /* BOOSTTRIVIALLOGADAPTER_H_ */
