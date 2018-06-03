#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iomanip>
#include <string>

class Employee final
{
public:
	Employee(std::string firstName, std::string lastName, int staffNumber, double salary) :
		firstName(firstName), lastName(lastName), staffNumber(staffNumber), salary(salary) { }

	~Employee() = default;

	Employee(const Employee& other) = default;
	Employee& operator=(const Employee& other) = default;
	Employee(Employee&& other) = default;
	Employee& operator=(Employee&& other) = default;

	std::string getFirstName() const noexcept {
		return firstName;
	}

	std::string getLastName() const noexcept {
		return lastName;
	}

	int getStaffNumber() const noexcept {
		return staffNumber;
	}

	double getSalary() const noexcept {
		return salary;
	}

	Employee changeSalary(double newSalary) const noexcept {
		return Employee(firstName, lastName, staffNumber, newSalary);
	}

private:
	const std::string firstName;
	const std::string lastName;
	const int staffNumber;
	const double salary;
};

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << "[ "
			<< employee.getFirstName() << " "
			<< employee.getLastName() << " "
			"<ID=" << employee.getStaffNumber() << ">" << " "
			<< "<Salary=$" << std::setprecision(2) << std::fixed << employee.getSalary() << ">"
			<< " ]";
	return os;
}

#endif
