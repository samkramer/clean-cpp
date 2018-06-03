#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <memory>
#include "address.h"

// Forward declaration
class Formatter;

class Customer
{
public:
	Customer(int customerId, std::string forename, std::string surname, Address address);
	~Customer();

	std::string getAsFormattedString(const std::unique_ptr<Formatter>& formatter) const;

private:
	class Impl;
	std::unique_ptr<Impl> impl;
};

#endif /* CUSTOMER_H_ */
