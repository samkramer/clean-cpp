#ifndef PLAINTEXTFORMATTER_H_
#define PLAINTEXTFORMATTER_H_

#include "formatter.h"

class PlainTextFormatter : public Formatter
{
public:
	virtual std::string format() const override {
		std::stringstream formattedString;
		formattedString << "[" << customerId << "]: "
				<< forename << " " << surname << ", "
				<< street << ", "
				<< city << ", " << state << " " << zipCode;
		return formattedString.str();
	}
};

#endif /* PLAINTEXTFORMATTER_H_ */
