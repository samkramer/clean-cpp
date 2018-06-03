#include "customer.h"

Customer::Customer(CustomerId customerId, std::string forename, std::string surname, Address address)
: customerId(customerId)
, forename(forename)
, surname(surname)
, address(address)
{}

std::string Customer::getAsFormattedString(const FormatterPtr& formatter) const
{
	std::string street = address.getStreet();
	std::string zipCode = address.getZipCodeAsString();
	std::string city = address.getCity();

	return formatter->
			withCustomerId(customerId.toString()).
			withForename(forename).
			withSurname(surname).
			withStreet(street).
			withZipCode(zipCode).
			withCity(city).
			format();
}
