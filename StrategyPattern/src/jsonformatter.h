#ifndef JSONFORMATTER_H_
#define JSONFORMATTER_H_

#include "formatter.h"

class JsonFormatter : public Formatter
{
public:
	virtual std::string format() const override;
};

#endif /* JSONFORMATTER_H_ */
