#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int age;
    double grade;

    Student(const string &n, int a, double g) : name(n), age(a), grade(g) {}
};

class StudentInformationSystem
{
private:
    vector<Student> students;

public:
    void addStudent(const string &name, int age, double grade)
    {
        students.emplace_back(name, age, grade);
    }

    void displayAllStudents()
    {
        cout << "Student Information:\n";
        for (const auto &student : students)
        {
            cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
        }
    }
};

int main()
{
    StudentInformationSystem sis;

    sis.addStudent("John Doe", 20, 85.5);
    sis.addStudent("Jane Smith", 22, 90.2);
    sis.addStudent("Bob Johnson", 21, 78.9);

    sis.displayAllStudents();

    return 0;
}
