#ifndef XMLFORMATTER_H_
#define XMLFORMATTER_H_

#include "formatter.h"

class XmlFormatter : public Formatter
{
public:
	virtual std::string format() const override {
		std::stringstream formattedString;
		formattedString << "<customer id=\"" << customerId << "\">" << std::endl
				<< "  <forename>" << forename << "</forename>" << std::endl
				<< "  <surname>" << surname << "</surname>" << std::endl
				<< "  <street>" << street << "</street>" << std::endl
				<< "  <city>" << city << "</city>" << std::endl
				<< "  <state>" << state << "</state>" << std::endl
				<< "  <zipCode>" << zipCode << "</zipCode>" << std::endl
				<< "</customer>" << std::endl;
		return formattedString.str();
	}
};

#endif /* XMLFORMATTER_H_ */
