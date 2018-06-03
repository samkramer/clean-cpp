#include "customer.h"
#include "customerid.h"
#include "formatter.h"

class Customer::Impl final
{
public:
	Impl(CustomerId customerId, std::string forename, std::string surname, Address address);
	~Impl() = default;

	std::string getAsFormattedString(const std::unique_ptr<Formatter>& formatter) const;

private:
	CustomerId customerId;
	std::string forename;
	std::string surname;
	Address address;
};

Customer::Impl::Impl(CustomerId customerId, std::string forename, std::string surname, Address address)
: customerId(customerId)
, forename(forename)
, surname(surname)
, address(address)
{}

std::string Customer::Impl::getAsFormattedString(const std::unique_ptr<Formatter>& formatter) const
{
	return formatter->
			withCustomerId(customerId.toString()).
			withForename(forename).
			withSurname(surname).
			withStreet(address.getStreet()).
			withZipCode(address.getZipCodeAsString()).
			withCity(address.getCity()).
			withState(address.getState()).
			format();
}

Customer::Customer(int customerId, std::string forename, std::string surname, Address address)
: impl { std::make_unique<Customer::Impl>(CustomerId(customerId), forename, surname, address) }
{}

Customer::~Customer() = default;

std::string Customer::getAsFormattedString(const std::unique_ptr<Formatter>& formatter) const
{
	return impl->getAsFormattedString(formatter);
}
