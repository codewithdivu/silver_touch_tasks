#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

// Initial version of a Serializable object
struct SerializableV1 {
    int data;

    template <typename Archive>
    void serialize(Archive& ar) {
        ar(data);
    }
};

// Updated version of the Serializable object
struct SerializableV2 {
    int data;
    string additionalData;

    template <typename Archive>
    void serialize(Archive& ar) {
        ar(data, additionalData);
    }
};

// Serialization function that handles versioning
template <typename Archive, typename Serializable>
void serializeWithVersion(Archive& ar, Serializable& obj, int version) {
    obj.serialize(ar);
}

// Explicit specialization for version 1
template <>
void serializeWithVersion<SerializableV2, SerializableV1>(SerializableV2& ar, SerializableV1& obj, int version) {
    // Serialize the common data
    ar.data = obj.data;

    // Upgrade from V1 to V2
    cout << "Upgrading to version 2..." << endl;
    SerializableV2 v2Obj;
    v2Obj.data = obj.data;
    v2Obj.additionalData = "DefaultAdditionalData";
    ar.additionalData = v2Obj.additionalData;
}

int main() {
    // Simulate deserialization from a file with version information
    int versionFromDisk = 2;  // Assume version retrieved from file

    // Deserialize based on version
    if (versionFromDisk == 1) {
        SerializableV1 obj;
        // Simulate loading from file
        obj.data = 42;
        cout << "Deserialized data from version 1." << endl;

        // Upgrade to the latest version
        SerializableV2 upgradedObj;
        serializeWithVersion(upgradedObj, obj, versionFromDisk);

        // Access upgraded data
        cout << "Upgraded data: " << upgradedObj.data << ", Additional Data: " << upgradedObj.additionalData << endl;
    } else if (versionFromDisk == 2) {
        SerializableV2 obj;
        // Simulate loading from file
        obj.data = 42;
        obj.additionalData = "LoadedAdditionalData";
        cout << "Deserialized data from version 2." << endl;

        // Access loaded data
        cout << "Loaded data: " << obj.data << ", Additional Data: " << obj.additionalData << endl;
    } else {
        cerr << "Unsupported version." << endl;
    }

    return 0;
}