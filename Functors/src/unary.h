#ifndef UNARY_H_
#define UNARY_H_

// Example of unary function -- functor with one parameter
class ToSquare {
public:
	constexpr int operator()(const int value) const noexcept {
		return value * value;
	}
};

#endif /* UNARY_H_ */
