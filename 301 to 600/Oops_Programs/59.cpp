#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;


class ServiceA {
public:
    void performOperation() const {
        cout << "ServiceA operation" << endl;
    }
};

class ServiceB {
public:
    void performOperation() const {
        cout << "ServiceB operation" << endl;
    }
};


class DIContainer {
private:
    unordered_map<string, function<void*()>> instances;

public:
    template <typename T>
    void registerInstance(const string& key) {
        instances[key] = []() { return new T(); };
    }

    template <typename T>
    T* resolveInstance(const string& key) {
        auto it = instances.find(key);
        if (it != instances.end()) {
            return static_cast<T*>(it->second());
        }
        return nullptr;
    }
};

int main() {
    DIContainer container;

    
    container.registerInstance<ServiceA>("serviceA");
    container.registerInstance<ServiceB>("serviceB");

    
    ServiceA* serviceA = container.resolveInstance<ServiceA>("serviceA");
    ServiceB* serviceB = container.resolveInstance<ServiceB>("serviceB");

    if (serviceA && serviceB) {
        serviceA->performOperation();
        serviceB->performOperation();
    } else {
        cout << "Failed to resolve instances." << endl;
    }

    return 0;
}
