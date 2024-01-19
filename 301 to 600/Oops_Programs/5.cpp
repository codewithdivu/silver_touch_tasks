#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
    virtual void execute() const = 0;
};

class Receiver {
public:
    void action() const {
        cout << "Receiver action\n";
    }
};

class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* rec) : receiver(rec) {}

    void execute() const override {
        receiver->action();
    }
};

class Invoker {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void executeCommand() const {
        command->execute();
    }
};

int main() {
    Receiver receiver;
    ConcreteCommand command(&receiver);
    Invoker invoker;

    invoker.setCommand(&command);
    invoker.executeCommand();

    return 0;
}
