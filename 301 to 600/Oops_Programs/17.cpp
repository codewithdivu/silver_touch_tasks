#include <iostream>
using namespace std;

class LoggingAspect {
public:
    void logBefore() const {
        cout << "Log: Before method execution\n";
    }

    void logAfter() const {
        cout << "Log: After method execution\n";
    }
};

class TargetClass {
public:
    void performAction() const {
        cout << "TargetClass performing action\n";
    }
};

class ProxyClass {
private:
    LoggingAspect loggingAspect;
    TargetClass target;

public:
    void performActionWithLogging() const {
        loggingAspect.logBefore();
        target.performAction();
        loggingAspect.logAfter();
    }
};

int main() {
    ProxyClass proxy;
    proxy.performActionWithLogging();

    return 0;
}
