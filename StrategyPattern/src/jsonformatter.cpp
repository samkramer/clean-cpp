#include "jsonformatter.h"
#include <nlohmann/json.hpp>

// REF:
// https://github.com/nlohmann/json

std::string JsonFormatter::format() const
{
	using json = nlohmann::json;

	json doc;
	doc["customer_id"] = customerId;
	doc["forename"] = forename;
	doc["surname"] = surname;
	doc["street"] = street;
	doc["zipCode"] = zipCode;
	doc["city"] = city;

	return doc.dump(4);
}
