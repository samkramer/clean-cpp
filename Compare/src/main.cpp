#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void printText(const std::string& text)
{
	std::cout << text << " ";
}

int main()
{
	std::vector<std::string> names1 = {"Peter", "Harry", "Julia", "John", "Antonio", "Glenn" };
	std::vector<std::string> names2 = {"Peter", "Harry", "Julia", "Johnson", "Antonio", "Glenn" };

	// C++14
	bool isEqual = std::equal(std::begin(names1), std::end(names1),
			std::begin(names2), std::end(names2));
	if (isEqual)
	{
		std::cout << "Content of both sequences are equal\n";
	}
	else
	{
		std::cout << "Content of both sequences differ\n";
	}

	bool isEqualFirstThreeChars = std::equal(std::begin(names1),
			std::end(names1), std::begin(names2), std::end(names2),
			[](const std::string& lhs, const std::string& rhs) {
				return (lhs.compare(0, 3, rhs, 0, 3) == 0);
			});
	if (isEqualFirstThreeChars)
	{
		std::cout << "Content of both sequences are equal\n";
	}
	else
	{
		std::cout << "Content of both sequences differ\n";
	}
}
