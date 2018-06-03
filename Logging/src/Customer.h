#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer
{
public:
	Customer() = default;
	virtual ~Customer() = default;

	virtual bool findCustomerById(int id) = 0;
};

#endif /* CUSTOMER_H_ */
