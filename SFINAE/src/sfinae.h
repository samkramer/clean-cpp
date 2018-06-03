#ifndef SFINAE_H_
#define SFINAE_H_

#include <iostream>
#include <type_traits>

template <typename T>
void print(T var, typename std::enable_if<std::is_enum<T>::value, T>::type* = 0)
{
	std::cout << "Calling overloaded print() for enumerations." << std::endl;
}

template <typename T>
void print(T var, typename std::enable_if<std::is_integral<T>::value, T>::type = 0)
{
	std::cout << "Calling overloaded print() for integral types." << std::endl;
}

template <typename T>
void print(T var, typename std::enable_if<std::is_floating_point<T>::value, T>::type = 0)
{
	std::cout << "Calling overloaded print() for floating point types." << std::endl;
}

template <typename T>
void print(const T& var, typename std::enable_if<std::is_class<T>::value, T>::type* = 0)
{
	std::cout << "Calling overloaded print() for classes." << std::endl;
}

#endif /* SFINAE_H_ */
