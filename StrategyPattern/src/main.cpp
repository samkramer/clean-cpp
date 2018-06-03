#include <iostream>
#include <memory>
#include "customer.h"
#include "address.h"
#include "plaintextformatter.h"
#include "xmlformatter.h"
#include "jsonformatter.h"

int main()
{
	Address address1;
	address1.setStreet("123 Maple Lane");
	address1.setCity("Atlanta");
	address1.setZipCode(30338);
	Customer c1(CustomerId(1), "Bill", "Smith", address1);

	auto textFormatter = std::make_unique<PlainTextFormatter>();
	std::cout << c1.getAsFormattedString(std::move(textFormatter)) << std::endl;

	auto xmlFormatter = std::make_unique<XmlFormatter>();
	std::cout << c1.getAsFormattedString(std::move(xmlFormatter)) << std::endl;

	auto jsonFormatter = std::make_unique<JsonFormatter>();
	std::cout << c1.getAsFormattedString(std::move(jsonFormatter)) << std::endl;

	return 0;
}
