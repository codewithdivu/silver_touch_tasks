#include <iostream>
#include <functional>
#include <vector>
#include <memory>
using namespace std;


class LoggingAspect {
public:
    template <typename Func>
    void before(const Func& func) {
        cout << "Before Function Call" << endl;
        func();
    }

    template <typename Func>
    void after(const Func& func) {
        func();
        cout << "After Function Call" << endl;
    }
};


class AspectFramework {
public:
    template <typename Aspect, typename Func>
    void apply(const Func& func) {
        Aspect aspect;
        aspect.before(func);
        
        aspect.after(func);
    }
};


class MyClass {
public:
    void myFunction() {
        cout << "Inside myFunction" << endl;
    }
};

int main() {
    MyClass obj;

    AspectFramework aspectFramework;
    
    aspectFramework.apply<LoggingAspect>([&obj]() {
        obj.myFunction();
    });

    return 0;
}
