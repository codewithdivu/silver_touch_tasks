#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(const string& n, double s) : name(n), salary(s) {}

    virtual double calculateSalary() const {
        return salary;
    }

    string getName() const {
        return name;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(const string& n, double s, double b) : Employee(n, s), bonus(b) {}

    double calculateSalary() const override {
        return salary + bonus;
    }
};

class Department {
private:
    string name;
    Manager* manager;

public:
    Department(const string& n, Manager* mgr) : name(n), manager(mgr) {}

    void promoteEmployee(Employee* employee) {
        cout << "Promoting employee " << employee->getName() << " in department " << name << endl;
        
    }
};

int main() {
    Manager manager("Alice", 50000.0, 10000.0);
    Employee employee("Bob", 40000.0);

    Department department("IT", &manager);
    department.promoteEmployee(&employee);

    return 0;
}