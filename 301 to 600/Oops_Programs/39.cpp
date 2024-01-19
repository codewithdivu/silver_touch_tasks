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
        // Implement serialization based on reflection
        // ...
    }

    static T deserialize(const SerializationContext& context) {
        T object;
        // Implement deserialization based on reflection
        // ...
        return object;
    }
};

// Example: A simple class for serialization
class Person {
public:
    string name;
    int age;

    // Reflect the fields for serialization
    REFLECT_FIELDS(name, age)
};

// Macros for reflection
#define REFLECT_FIELDS(...) \
    template <typename Serializer> \
    friend void serialize(Serializer& s, const Person& obj) { \
        s(__VA_ARGS__, &obj); \
    } \
    template <typename Deserializer> \
    friend void deserialize(Deserializer& d, Person& obj) { \
        d(__VA_ARGS__, &obj); \
    }

// Serialization functions
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
    // Convert int to string for serialization
    s.serialize(name, to_string(field));
}

template <typename Deserializer>
void deserialize(Deserializer& d, const string& name, int& field) {
    // Convert string to int for deserialization
    field = stoi(d.deserialize(name));
}

// Example usage
void exampleSerialization() {
    Person person;
    person.name = "Alice";
    person.age = 30;

    SerializationContext context;
    ReflectiveSerializer<Person>::serialize(person, context);

    // Later, deserialize from the context
    Person deserializedPerson = ReflectiveSerializer<Person>::deserialize(context);
}

int main() {
    // Example usage of the serialization library

    // Create a person
    Person person;
    person.name = "Alice";
    person.age = 30;

    // Serialize the person
    SerializationContext context;
    ReflectiveSerializer<Person>::serialize(person, context);

    // Deserialize the person
    Person deserializedPerson = ReflectiveSerializer<Person>::deserialize(context);

    // Display the deserialized person
    cout << "Deserialized Person: Name = " << deserializedPerson.name
              << ", Age = " << deserializedPerson.age << endl;

    return 0;
}