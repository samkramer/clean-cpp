#include "sfinae.h"

enum Enumeration1 {
	Literal1, Literal2
};

enum class Enumeration2 : int {
	Literal1, Literal2
};

class Clazz { };

// Calling overloaded print() for enumerations.
// Calling overloaded print() for enumerations.
// Calling overloaded print() for classes.
// Calling overloaded print() for integral types.
// Calling overloaded print() for floating point types.
// Calling overloaded print() for floating point types.
int main()
{
	Enumeration1 enum1 { };
	print(enum1);

	Enumeration2 enum2 { };
	print(enum2);

	Clazz instance { };
	print(instance);

	print(42);
	print(42.0f);
	print(42.0);
}
