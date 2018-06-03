#include <iostream>
#include <vector>
#include "employee.h"

int main()
{
	Employee e1("Jane", "Smith", 100, 45000.00);
	Employee e2("Mike", "Jones", 101, 57000.00);
	Employee e3("Brian", "Carter", 102, 48000.00);

	std::vector<Employee> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);

	for (const auto& emp : employees) {
		std::cout << emp << std::endl;
	}

	Employee e2_c = e2.changeSalary(59000.00);
	std::cout << "<Original> " << e2 << std::endl;
	std::cout << "<Changed> " << e2_c << std::endl;
}
