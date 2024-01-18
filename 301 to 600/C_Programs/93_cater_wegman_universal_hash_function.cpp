#include <iostream>
#include <vector>
#include <random>
using namespace std;

class CarterWegmanHash
{
private:
    uint64_t p;
    uint64_t a;
    uint64_t b;

public:
    CarterWegmanHash(uint64_t prime) : p(prime)
    {

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<uint64_t> distribution(1, p - 1);

        a = distribution(gen);
        b = distribution(gen);
    }

    uint64_t hash(uint64_t key) const
    {
        return (a * key + b) % p;
    }
};

int main()
{

    uint64_t prime = 4294967311;
    CarterWegmanHash hashFunction(prime);

    uint64_t key1 = 12345;
    uint64_t key2 = 67890;

    uint64_t hash1 = hashFunction.hash(key1);
    uint64_t hash2 = hashFunction.hash(key2);

    cout << "Hash(" << key1 << ") = " << hash1 << endl;
    cout << "Hash(" << key2 << ") = " << hash2 << endl;

    return 0;
}
