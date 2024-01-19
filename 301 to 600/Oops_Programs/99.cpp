#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declarations
class Course;
class Student;
class Instructor;

// Class representing a Course
class Course {
private:
    string title;
    string instructorName;
    vector<string> assignments;
    vector<Student*> enrolledStudents;

public:
    Course(const string& title, const string& instructorName)
        : title(title), instructorName(instructorName) {}

    const string& getTitle() const {
        return title;
    }

    const string& getInstructorName() const {
        return instructorName;
    }

    void addAssignment(const string& assignment) {
        assignments.push_back(assignment);
    }

    const vector<string>& getAssignments() const {
        return assignments;
    }

    void enrollStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    const vector<Student*>& getEnrolledStudents() const {
        return enrolledStudents;
    }
};

// Class representing a Student
class Student {
private:
    string name;
    vector<Course*> enrolledCourses;

public:
    Student(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void enrollInCourse(Course* course) {
        enrolledCourses.push_back(course);
        course->enrollStudent(this);
    }

    void completeAssignment(Course* course, const string& assignment) {
        cout << name << " completed assignment '" << assignment << "' in course '" << course->getTitle() << "'.\n";
    }

    void viewEnrolledCourses() const {
        cout << name << "'s Enrolled Courses:\n";
        for (const auto& course : enrolledCourses) {
            cout << " - " << course->getTitle() << " (Instructor: " << course->getInstructorName() << ")\n";
        }
        cout << "----------------------------------\n";
    }
};

// Class representing an Instructor
class Instructor {
private:
    string name;

public:
    Instructor(const string& name) : name(name) {}

    const string& getName() const {
        return name;
    }

    void assignGrade(Student* student, Course* course, const string& assignment, int grade) const {
        cout << "Instructor " << name << " assigned grade " << grade << " to student " << student->getName()
             << " for assignment '" << assignment << "' in course '" << course->getTitle() << "'.\n";
    }
};

int main() {
    // Create instances of courses, students, and instructor
    Course cppCourse("C++ Programming", "John Instructor");
    cppCourse.addAssignment("Introduction to C++");
    cppCourse.addAssignment("Object-Oriented Programming");

    Course webDevCourse("Web Development", "Jane Instructor");
    webDevCourse.addAssignment("HTML Basics");
    webDevCourse.addAssignment("CSS Styling");

    Student student1("Alice");
    Student student2("Bob");

    Instructor instructor("Dr. Smith");

    // Enroll students in courses
    student1.enrollInCourse(&cppCourse);
    student2.enrollInCourse(&webDevCourse);

    // View enrolled courses for each student
    student1.viewEnrolledCourses();
    student2.viewEnrolledCourses();

    // Students complete assignments
    student1.completeAssignment(&cppCourse, "Introduction to C++");
    student2.completeAssignment(&webDevCourse, "HTML Basics");

    // Instructor assigns grades
    instructor.assignGrade(&student1, &cppCourse, "Introduction to C++", 90);
    instructor.assignGrade(&student2, &webDevCourse, "HTML Basics", 85);

    return 0;
}
