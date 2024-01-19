#include <iostream>
using namespace std;

class Subject {
public:
    virtual void request() const = 0;
};

class RealSubject : public Subject {
public:
    void request() const override {
        cout << "Real Subject handles the request\n";
    }
};

class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy(RealSubject* realSubject_) : realSubject(realSubject_) {}

    void request() const override {
        realSubject->request();
    }
};

int main() {
    RealSubject* r=new RealSubject();
    Proxy proxy(r);
    proxy.request();
    return 0;
}
