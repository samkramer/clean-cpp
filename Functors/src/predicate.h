#ifndef PREDICATE_H_
#define PREDICATE_H_

#include <type_traits>

class IsOdd {
public:
	constexpr bool operator()(const int value) const noexcept {
		return (value % 2) != 0;
	}
};

template <typename T>
class IsOddNumeric {
public:
	static_assert(std::is_integral<T>::value,
			"IsOddNumeric requires an integer type for template parameter");

	constexpr bool operator()(const T value) const noexcept {
			return (value % 2) != 0;
		}
};

#endif /* PREDICATE_H_ */
