#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

class Address
{
public:
	Address() = default;
	~Address() = default;

	std::string getStreet() const {
		return street;
	}

	std::string getCity() const {
		return city;
	}

	std::string getState() const {
		return state;
	}

	std::string getZipCodeAsString() const {
		return std::to_string(zipCode);
	}

	void setStreet(std::string street) {
		this->street = street;
	}

	void setCity(std::string city) {
		this->city = city;
	}

	void setState(std::string state) {
		this->state = state;
	}

	void setZipCode(int zipCode) {
		this->zipCode = zipCode;
	}

private:
	std::string street;
	std::string city;
	std::string state;
	int zipCode {0};
};

#endif /* ADDRESS_H_ */
