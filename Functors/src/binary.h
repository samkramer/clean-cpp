#ifndef BINARY_H_
#define BINARY_H_

template <typename T>
class IsGreaterOrEqual {
public:
	bool operator()(const T& lhs, const T& rhs) const noexcept {
		return lhs >= rhs;
	}
};

#endif /* BINARY_H_ */
