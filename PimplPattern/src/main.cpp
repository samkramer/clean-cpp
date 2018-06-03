#include <iostream>
#include <memory>
#include "customer.h"
#include "address.h"
#include "customerid.h"
#include "plaintextformatter.h"
#include "xmlformatter.h"

int main()
{
	Address address1;
	address1.setStreet("123 Maple Lane");
	address1.setCity("Atlanta");
	address1.setState("GA");
	address1.setZipCode(30338);

	int customerId = 1;
	Customer c1(customerId, "Bill", "Smith", address1);

	auto textFormatter = std::make_unique<PlainTextFormatter>();
	std::cout << c1.getAsFormattedString(std::move(textFormatter)) << std::endl;

	auto xmlFormatter = std::make_unique<XmlFormatter>();
	std::cout << c1.getAsFormattedString(std::move(xmlFormatter)) << std::endl;

	return 0;
}
