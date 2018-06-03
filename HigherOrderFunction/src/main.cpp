#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

template <typename CONTAINER_TYPE, typename UNARY_FUNCTION_TYPE>
void myForEach(const CONTAINER_TYPE& container, UNARY_FUNCTION_TYPE unaryFunction)
{
	for (const auto& element : container) {
		unaryFunction(element);
	}
}

template <typename CONTAINER_TYPE, typename UNARY_OPERATION_TYPE>
void myTransform(CONTAINER_TYPE& container, UNARY_OPERATION_TYPE unaryOperator)
{
	for (auto& element : container) {
		element = unaryOperator(element);
	}
}

template <typename NUMBER_TYPE>
class ToSquare
{
public:
	NUMBER_TYPE operator()(const NUMBER_TYPE& number) const noexcept {
		return number * number;
	}
};

template <typename T>
void printOnStdOut(const T& thing)
{
	std::cout << thing << " ";
}

int main()
{
	std::vector<int> numbers(10);
	std::iota(numbers.begin(), numbers.end(), 1);

	myTransform(numbers, ToSquare<int>());

	std::function<void(int)> printNumbers = printOnStdOut<int>;
	myForEach(numbers, printNumbers);
	std::cout << std::endl;
}
