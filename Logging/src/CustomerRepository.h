#ifndef CUSTOMERREPOSITORY_H_
#define CUSTOMERREPOSITORY_H_

#include "Customer.h"
#include "LoggingFacility.h"

class CustomerRepository : public Customer
{
public:
	CustomerRepository() = delete;
	explicit CustomerRepository(const Logger& loggingService) : logger {loggingService} { }

	virtual bool findCustomerById(int id) override;

private:
	Logger logger;
};

#endif /* CUSTOMERREPOSITORY_H_ */
