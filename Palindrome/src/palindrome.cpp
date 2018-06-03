#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

template<typename T>
void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "")
{
	std::cout << optstr;
	for (const auto& elem : coll) {
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}

class IsPalindrome
{
public:
	bool operator()(const std::string& word) const
	{
		const auto middleOfWord = begin(word) + word.size() / 2;
		return std::equal(begin(word), middleOfWord, rbegin(word));
	}
};

bool is_palindrome(const std::string& s)
{
	return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

void testPalindrome(const std::string& s)
{
	std::cout << "\"" << s << "\" " << (is_palindrome(s) ? "is" : "is not")
			<< " a palindrome\n";
}

int main()
{
	testPalindrome("radar");
	testPalindrome("hello");

	std::vector<std::string> words = { "dad", "hello", "radar", "vector", "level" };
	PRINT_ELEMENTS(words, "words: ");

	// Example of Map
	std::vector<std::string> angleWords;
	std::transform(begin(words), end(words), std::back_inserter(angleWords),
			[](const std::string& w) {return "<" + w + ">";});
	PRINT_ELEMENTS(angleWords, "angle words: ");

	// Example of Filter
	words.erase(std::remove_if(begin(words), end(words), IsPalindrome()),
			end(words));
	PRINT_ELEMENTS(words, "filtered words: ");

	std::vector<int> all(10);
	std::iota(std::begin(all), std::end(all), 1); // Fill with 1, 2, ..., 10
	PRINT_ELEMENTS(all, "all: ");

	// Example of Reduce
	std::vector<int> v(all);
	int sum = std::accumulate(v.begin(), v.end(), 0);
	int product = std::accumulate(v.begin(), v.end(), 1,
			std::multiplies<int>());
	std::string s = std::accumulate(std::next(v.begin()), v.end(),
			std::to_string(v[0]), // start with first element
			[](std::string a, int b) {
				return a + '-' + std::to_string(b);
			});

	std::cout << "sum: " << sum << '\n' << "product: " << product << '\n'
			<< "dash-separated string: " << s << '\n';

	std::vector<int> numbers {12, 45, -102, 33, 78, -8, 100, 2017, -110};
	int maxValue = std::accumulate(numbers.begin(), numbers.end(), 0,
			[](int lhs, int rhs) { return lhs > rhs ? lhs : rhs; });
	std::cout << "maxValue = " << maxValue << std::endl;

	std::vector<int> even;
	std::copy_if(begin(all), end(all), std::back_inserter(even),
			[](int n) {return n % 2 == 0;});
	PRINT_ELEMENTS(even, "even: ");

	// Example of Map
	std::transform(begin(even), end(even), begin(even),
			[](int n) {return n * n * n;});
	PRINT_ELEMENTS(even, "evenCubed: ");
}
