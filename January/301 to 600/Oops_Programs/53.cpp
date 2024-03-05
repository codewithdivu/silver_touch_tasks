#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;


struct SerializableV1 {
    int data;

    template <typename Archive>
    void serialize(Archive& ar) {
        ar(data);
    }
};


struct SerializableV2 {
    int data;
    string additionalData;

    template <typename Archive>
    void serialize(Archive& ar) {
        ar(data, additionalData);
    }
};


template <typename Archive, typename Serializable>
void serializeWithVersion(Archive& ar, Serializable& obj, int version) {
    obj.serialize(ar);
}


template <>
void serializeWithVersion<SerializableV2, SerializableV1>(SerializableV2& ar, SerializableV1& obj, int version) {
    
    ar.data = obj.data;

    
    cout << "Upgrading to version 2..." << endl;
    SerializableV2 v2Obj;
    v2Obj.data = obj.data;
    v2Obj.additionalData = "DefaultAdditionalData";
    ar.additionalData = v2Obj.additionalData;
}

int main() {
    
    int versionFromDisk = 2;  

    
    if (versionFromDisk == 1) {
        SerializableV1 obj;
        
        obj.data = 42;
        cout << "Deserialized data from version 1." << endl;

        
        SerializableV2 upgradedObj;
        serializeWithVersion(upgradedObj, obj, versionFromDisk);

        
        cout << "Upgraded data: " << upgradedObj.data << ", Additional Data: " << upgradedObj.additionalData << endl;
    } else if (versionFromDisk == 2) {
        SerializableV2 obj;
        
        obj.data = 42;
        obj.additionalData = "LoadedAdditionalData";
        cout << "Deserialized data from version 2." << endl;

        
        cout << "Loaded data: " << obj.data << ", Additional Data: " << obj.additionalData << endl;
    } else {
        cerr << "Unsupported version." << endl;
    }

    return 0;
}