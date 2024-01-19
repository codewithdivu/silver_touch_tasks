#include <iostream>
#include <tuple>
#include <string>
using namespace std;

// Serialization trait for types
template <typename T>
struct Serialize {
    static string serialize(const T& value) {
        return to_string(value);
    }

    static T deserialize(const string& str) {
        return static_cast<T>(stoi(str));
    }
};

// Serialize and Deserialize string directly
template <>
struct Serialize<string> {
    static string serialize(const string& value) {
        return value;
    }

    static string deserialize(const string& str) {
        return str;
    }
};

// Serialize and Deserialize tuple recursively
template <typename... Args>
struct Serialize<tuple<Args...>> {
    static string serialize(const tuple<Args...>& t) {
        return serializeTuple(t, index_sequence_for<Args...>{});
    }

    static tuple<Args...> deserialize(const string& str) {
        return deserializeTuple<Args...>(str, index_sequence_for<Args...>{});
    }

private:
    template <typename... TupleArgs, size_t... Is>
    static string serializeTuple(const tuple<TupleArgs...>& t, index_sequence<Is...>) {
        return ((Serialize<TupleArgs>::serialize(get<Is>(t)) + ",") + ...);
    }

    template <typename... TupleArgs, size_t... Is>
    static tuple<TupleArgs...> deserializeTuple(const string& str, index_sequence<Is...>) {
        istringstream stream(str);
        return make_tuple(Serialize<TupleArgs>::deserialize(parseUntilComma(stream))...);
    }

    static string parseUntilComma(istringstream& stream) {
        string token;
        getline(stream, token, ',');
        return token;
    }
};

// Example usage
int main() {
    // Serialize
    tuple<int, double, string> data = {42, 3.14, "Hello"};
    string serialized = Serialize<decltype(data)>::serialize(data);
    cout << "Serialized: " << serialized << endl;

    // Deserialize
    auto deserialized = Serialize<decltype(data)>::deserialize(serialized);
    cout << "Deserialized: {" << get<0>(deserialized) << ", " << get<1>(deserialized) << ", " << get<2>(deserialized) << "}" << endl;

    return 0;
}
