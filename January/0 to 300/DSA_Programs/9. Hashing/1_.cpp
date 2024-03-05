#include <iostream>
#include <bits/stdc++.h>

class HashTable
{
private:
    static const int numBuckets = 20;
    vector<list<int>> table;

    int hashFunction(int key)
    {
        return key % numBuckets;
    }

public:
    void insert(int element)
    {
        int index = hashFunction(element);
        table[index].push_back(element);
    }
    void remove(int element)
    {
        int index = hashFunction(element);
        table[index].pop_back(element);
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        list<int> bucket = table[index];

        for (auto it = bucket)
        {
            if (*it == key)
            {
                return true;
            }
        }
        return false;
    }

    void display() const
    {
        for (int i = 0; i < numBuckets; ++i)
        {
            cout << "Bucket " << i << ": ";
            for (int key : table[i])
            {
                cout << key << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable hashTable;

    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);
    hashTable.insert(15);

    cout << "Hash Table contents:" << endl;
    hashTable.display();

    int keyToSearch = 20;
    if (hashTable.search(keyToSearch))
    {
        cout << "Key " << keyToSearch << " found in the hash table." << endl;
    }
    else
    {
        cout << "Key " << keyToSearch << " not found in the hash table." << endl;
    }

    int keyToRemove = 30;
    hashTable.remove(keyToRemove);

    cout << "\nHash Table contents after removing " << keyToRemove << ":" << endl;
    hashTable.display();
    return 0;
}