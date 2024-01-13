#include <iostream>
#include <vector>
using namespace std;

class Command
{
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

class LightOnCommand : public Command
{
private:
    string device;

public:
    LightOnCommand(const string &device) : device(device) {}

    void execute() const override
    {
        cout << "Turning on " << device << endl;
    }
};

class LightOffCommand : public Command
{
private:
    string device;

public:
    LightOffCommand(const string &device) : device(device) {}

    void execute() const override
    {
        cout << "Turning off " << device << endl;
    }
};

class RemoteControl
{
private:
    Command *command;

public:
    void setCommand(Command *cmd)
    {
        this->command = cmd;
    }
    void pressButton()
    {
        command->execute();
    }
};

int main()
{
    string light = "Living Room Light";
    string fan = "Ceiling Fan";

    LightOnCommand turnOnLight(light);
    LightOffCommand turnOffLight(light);
    LightOnCommand turnOnFan(fan);
    LightOffCommand turnOffFan(fan);

    RemoteControl remote;

    remote.setCommand(&turnOnLight);
    remote.pressButton();

    remote.setCommand(&turnOffLight);
    remote.pressButton();

    remote.setCommand(&turnOnFan);
    remote.pressButton();

    remote.setCommand(&turnOffFan);
    remote.pressButton();
    return 0;
}