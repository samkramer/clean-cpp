#include "formatter.h"

Formatter& Formatter::withCustomerId(std::string_view customerId)
{
	this->customerId = customerId;
	return *this;
}

Formatter& Formatter::withForename(std::string_view forename)
{
	this->forename = forename;
	return *this;
}

Formatter& Formatter::withSurname(std::string_view surname)
{
	this->surname = surname;
	return *this;
}

Formatter& Formatter::withStreet(std::string_view street)
{
	this->street = street;
	return *this;
}

Formatter& Formatter::withZipCode(std::string_view zipCode)
{
	this->zipCode = zipCode;
	return *this;
}

Formatter& Formatter::withCity(std::string_view city)
{
	this->city = city;
	return *this;
}

Formatter& Formatter::withState(std::string_view state)
{
	this->state = state;
	return *this;
}
