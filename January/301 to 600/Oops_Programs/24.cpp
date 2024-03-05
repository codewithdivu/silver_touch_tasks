#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() {}

public:
    static Singleton* getInstance() {
        if (!instance) {
            lock_guard<mutex> lock(mtx);
            if (!instance) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();

    cout << "Are instances the same? " << (singleton1 == singleton2 ? "Yes" : "No") << endl;

    return 0;
}
