#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include "customerid.h"
#include "address.h"
#include "formatter.h"

class Customer
{
public:
	Customer(CustomerId customerId, std::string forename, std::string surname, Address address);

	std::string getAsFormattedString(const FormatterPtr& formatter) const;

private:
	CustomerId customerId;
	std::string forename;
	std::string surname;
	Address address;
};

#endif /* CUSTOMER_H_ */
