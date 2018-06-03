#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "randomgenerator.h"
#include "unary.h"
#include "predicate.h"
#include "binary.h"

template <typename T>
void print(const std::vector<T>& v)
{
	for (T n : v) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
}

class IncreasingNumberGenerator
{
public:
	int operator()() noexcept {
		return number++;
	}

private:
	int number {0};
};

void testIncreasingNumberGenerator()
{
	IncreasingNumberGenerator numGen;
	std::cout << numGen() << " " << numGen() << " " << numGen() << std::endl;
}

void testGenerateIncreasingNumberGenerator()
{
	const size_t AMOUNT_OF_NUMBERS {10};
	std::vector<int> numbers(AMOUNT_OF_NUMBERS);
	std::generate(std::begin(numbers), std::end(numbers), IncreasingNumberGenerator());
	print(numbers);
}

void testIota()
{
	const size_t AMOUNT_OF_NUMBERS {10};
	std::vector<int> numbers(AMOUNT_OF_NUMBERS);
	std::iota(numbers.begin(), numbers.end(), 1);
	print(numbers);
}

void testRandomGenerator()
{
	RandomNumberGenerator<int> randGen;

	const size_t AMOUNT_OF_NUMBERS {10};
	std::vector<int> randomNumbers(AMOUNT_OF_NUMBERS);
	std::generate(std::begin(randomNumbers), std::end(randomNumbers), std::ref(randGen));
	print(randomNumbers);

}

void testUnary()
{
	const size_t AMOUNT_OF_NUMBERS {10};
	std::vector<int> numbers(AMOUNT_OF_NUMBERS);
	std::iota(numbers.begin(), numbers.end(), 1);
	std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), ToSquare());
	print(numbers);
}

void testUnaryPredicate()
{
	std::vector<int> numbers(10);
	std::iota(numbers.begin(), numbers.end(), 1);
	numbers.erase( std::remove_if(std::begin(numbers), std::end(numbers), IsOdd()),
			std::end(numbers) );
	print(numbers);
}

void testUnaryPredicateTemplate()
{
	using Vector = std::vector<int>;

	Vector numbers(10);
	std::iota(numbers.begin(), numbers.end(), 1);
	numbers.erase( std::remove_if(std::begin(numbers), std::end(numbers), IsOddNumeric<Vector::value_type>()),
			std::end(numbers) );
	print(numbers);
}

void testBinary()
{
	std::vector<int> numbers(10);
	std::iota(numbers.begin(), numbers.end(), 1);
	// std::sort(numbers.begin(), numbers.end(), IsGreaterOrEqual<int>());
	std::sort(numbers.begin(), numbers.end(), std::greater<int>());
	print(numbers);
}

int main()
{
	testIncreasingNumberGenerator();
	testGenerateIncreasingNumberGenerator();
	testIota();
	testRandomGenerator();

	testUnary();
	testUnaryPredicate();
	testUnaryPredicateTemplate();
	testBinary();

}
