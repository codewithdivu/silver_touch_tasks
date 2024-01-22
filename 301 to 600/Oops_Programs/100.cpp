#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Employee {
private:
    string name;
    int employeeId;
    string designation;

public:
    Employee(const string& name, int employeeId, const string& designation)
        : name(name), employeeId(employeeId), designation(designation) {}

    const string& getName() const {
        return name;
    }

    int getEmployeeId() const {
        return employeeId;
    }

    const string& getDesignation() const {
        return designation;
    }
};


class Salary {
private:
    double baseSalary;
    double bonus;

public:
    Salary(double baseSalary, double bonus) : baseSalary(baseSalary), bonus(bonus) {}

    double calculateTotalSalary() const {
        return baseSalary + bonus;
    }
};


class Payroll {
private:
    vector<Employee> employees;
    vector<Salary> salaries;

public:
    void addEmployee(const Employee& employee, const Salary& salary) {
        employees.push_back(employee);
        salaries.push_back(salary);
    }

    void generatePayStubs() const {
        cout << "Pay Stubs:" << endl;
        cout << "----------------------------------------" << endl;

        for (size_t i = 0; i < employees.size(); ++i) {
            cout << "Employee ID: " << employees[i].getEmployeeId() << endl;
            cout << "Name: " << employees[i].getName() << endl;
            cout << "Designation: " << employees[i].getDesignation() << endl;
            cout << "Base Salary: $" << salaries[i].calculateTotalSalary() << endl;
            cout << "----------------------------------------" << endl;
        }
    }
};

int main() {
    
    Employee emp1("John Doe", 101, "Software Engineer");
    Employee emp2("Jane Smith", 102, "Product Manager");

    Salary salary1(60000.0, 5000.0);
    Salary salary2(80000.0, 7000.0);

    
    Payroll payroll;
    payroll.addEmployee(emp1, salary1);
    payroll.addEmployee(emp2, salary2);

    
    payroll.generatePayStubs();

    return 0;
}
