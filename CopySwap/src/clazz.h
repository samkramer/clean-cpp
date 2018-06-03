#ifndef CLAZZ_H_
#define CLAZZ_H_

#include <cstddef>
#include <cstring>
#include <algorithm>
#include <utility>

class Clazz final
{
public:
	Clazz() : resourceToManage { nullptr }, size{0}	{ }

	Clazz(const std::size_t size) : resourceToManage { new char[size+1]() }, size{size} {	}

	Clazz(const std::size_t size, char ch) : resourceToManage { new char[size+1]() }, size{size}
	{
		for (std::size_t i = 0; i < size; ++i) {
			resourceToManage[i] = ch;
		}
	}

	Clazz(const Clazz& other) : Clazz { other.size } {
		std::copy(other.resourceToManage, other.resourceToManage + other.size, resourceToManage);
	}

	Clazz& operator=(Clazz other) {
		swap(other);
		return *this;
	}

	~Clazz() {
		delete [] resourceToManage;
	}

	std::size_t getSize() const { return size; }
	const char* getResource() const { return resourceToManage; }

private:
	void swap(Clazz& other) noexcept
	{
		using std::swap;
		swap(resourceToManage, other.resourceToManage);
		swap(size, other.size);
	}

private:
	char* resourceToManage;
	std::size_t size;
};

std::ostream& operator<<(std::ostream& os, const Clazz& c)
{
	os << "[ "
			<< "Buffer Size: " << c.getSize() << " "
			<< "Resource: " << c.getResource() << " "
			<< " ]";
	return os;
}

#endif /* CLAZZ_H_ */
