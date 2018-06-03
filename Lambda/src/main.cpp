#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>

int main()
{
	std::vector<std::string> quote {"One", "small", "step", "for", "a", "man"};

	std::vector<std::string> result;
	std::transform(std::begin(quote), std::end(quote), std::back_inserter(result),
			[](const std::string& word) { return "<" + word + ">";});
	std::for_each(std::begin(result), std::end(result),
			[](const std::string& word) { std::cout << word << " "; });
	std::cout << std::endl;


	// C++14 only -- generic lambda expressions
	auto square = [](const auto& value) noexcept { return value * value; };

	auto res1 = square(12.56);
	auto res2 = square(-6);
	auto res3 = square(std::complex<double>(4.0, 2.5));
	std::cout << "result 1: " << res1 << "\n";
	std::cout << "result 2: " << res2 << "\n";
	std::cout << "result 3: " << res3 << "\n";
}
