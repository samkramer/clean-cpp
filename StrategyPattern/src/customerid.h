#ifndef CUSTOMERID_H_
#define CUSTOMERID_H_

#include <string>

class CustomerId
{
public:
	CustomerId(int id): id(id) {}

	int getId() const {
		return id;
	}

	std::string toString() const {
		const int numberOfZeros = 5;
		std::string strId = std::string(numberOfZeros, '0').append(std::to_string(id));
		return strId;
	}

private:
	int id;
};

#endif /* CUSTOMERID_H_ */
