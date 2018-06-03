#include "CustomerRepository.h"
#include <string>

bool CustomerRepository::findCustomerById(int id)
{
	logger->writeInfoEntry("Starting to search for customer with ID: " + std::to_string(id));
	return true;
}
