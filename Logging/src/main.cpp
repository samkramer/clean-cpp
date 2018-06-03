#include <iostream>

#include "LoggerFactory.h"
#include "CustomerRepository.h"

// Example of Dependency Injection design pattern
// @see Clean C++ Chapter 9
int main()
{
	// TODO: specify path of configuration file name
	std::string configurationFileName;
	Logger logger = LoggerFactory::create(configurationFileName);

	auto customerRepository = std::make_shared<CustomerRepository>(logger);
	customerRepository->findCustomerById(23);
}
