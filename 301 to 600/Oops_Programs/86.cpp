#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class representing a Task
class Task {
private:
    string name;
    string description;
    bool completed;

public:
    Task(const string& taskName, const string& taskDescription)
        : name(taskName), description(taskDescription), completed(false) {}

    const string& getName() const {
        return name;
    }

    const string& getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void markCompleted() {
        completed = true;
        cout << "Task '" << name << "' marked as completed.\n";
    }
};

// Class representing a Project
class Project {
private:
    string name;
    vector<Task> tasks;

public:
    Project(const string& projectName) : name(projectName) {}

    const string& getName() const {
        return name;
    }

    void addTask(const Task& task) {
        tasks.push_back(task);
        cout << "Task '" << task.getName() << "' added to project '" << name << "'.\n";
    }

    void listTasks() const {
        cout << "Tasks for project '" << name << "':\n";
        for (const Task& task : tasks) {
            cout << "- " << task.getName() << " (" << (task.isCompleted() ? "Completed" : "Incomplete") << ")\n";
        }
    }
};

// Class representing a Team Member
class TeamMember {
private:
    string name;
    vector<Task> assignedTasks;

public:
    TeamMember(const string& memberName) : name(memberName) {}

    const string& getName() const {
        return name;
    }

    void assignTask(const Task& task) {
        assignedTasks.push_back(task);
        cout << "Task '" << task.getName() << "' assigned to team member '" << name << "'.\n";
    }

    void listAssignedTasks() const {
        cout << "Tasks assigned to team member '" << name << "':\n";
        for (const Task& task : assignedTasks) {
            cout << "- " << task.getName() << " (" << (task.isCompleted() ? "Completed" : "Incomplete") << ")\n";
        }
    }
};

int main() {
    Project project("Software Development");
    Task task1("Implement Feature A", "Implement the new feature A for the project");
    Task task2("Bug Fixing", "Fix bugs in the existing codebase");

    project.addTask(task1);
    project.addTask(task2);

    project.listTasks();

    TeamMember developer("John");
    TeamMember tester("Alice");

    developer.assignTask(task1);
    tester.assignTask(task2);

    developer.listAssignedTasks();
    tester.listAssignedTasks();

    task1.markCompleted();

    developer.listAssignedTasks();
    tester.listAssignedTasks();

    return 0;
}
