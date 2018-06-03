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
	std::vector<std::string> names = {"Peter", "Harry", "Julia", "Marc", "Antonio", "Glenn" };
	std::sort(std::begin(names), std::end(names));
	std::for_each(std::begin(names), std::end(names), printText);
}
