#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <unordered_map>
using namespace std;

class SerializationContext {
private:
    unordered_map<string, string> data;

public:
    void serialize(const string& key, const string& value) {
        data[key] = value;
    }

    string deserialize(const string& key) const {
        auto it = data.find(key);
        return (it != data.end()) ? it->second : "";
    }
};

template <typename T>
class ReflectiveSerializer {
public:
    static void serialize(const T& object, SerializationContext& context) {
        
        
    }

    static T deserialize(const SerializationContext& context) {
        T object;
        
        
        return object;
    }
};


class Person {
public:
    string name;
    int age;

    
    REFLECT_FIELDS(name, age)
};


#define REFLECT_FIELDS(...) \
    template <typename Serializer> \
    friend void serialize(Serializer& s, const Person& obj) { \
        s(__VA_ARGS__, &obj); \
    } \
    template <typename Deserializer> \
    friend void deserialize(Deserializer& d, Person& obj) { \
        d(__VA_ARGS__, &obj); \
    }


template <typename Serializer>
void serialize(Serializer& s, const string& name, string& field) {
    s.serialize(name, field);
}

template <typename Deserializer>
void deserialize(Deserializer& d, const string& name, string& field) {
    field = d.deserialize(name);
}

template <typename Serializer>
void serialize(Serializer& s, const string& name, int& field) {
    
    s.serialize(name, to_string(field));
}

template <typename Deserializer>
void deserialize(Deserializer& d, const string& name, int& field) {
    
    field = stoi(d.deserialize(name));
}


void exampleSerialization() {
    Person person;
    person.name = "Alice";
    person.age = 30;

    SerializationContext context;
    ReflectiveSerializer<Person>::serialize(person, context);

    
    Person deserializedPerson = ReflectiveSerializer<Person>::deserialize(context);
}

int main() {
    

    
    Person person;
    person.name = "Alice";
    person.age = 30;

    
    SerializationContext context;
    ReflectiveSerializer<Person>::serialize(person, context);

    
    Person deserializedPerson = ReflectiveSerializer<Person>::deserialize(context);

    
    cout << "Deserialized Person: Name = " << deserializedPerson.name
              << ", Age = " << deserializedPerson.age << endl;

    return 0;
}