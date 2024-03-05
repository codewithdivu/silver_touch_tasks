#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a == 0 ? b : a;
}

using namespace std;

long long mod_pow(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    base %= modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

bool is_prime(long long num)
{
    if (num <= 1)
    {
        return false;
    }

    for (long long i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long generate_prime()
{
    long long candidate;

    do
    {
        candidate = rand() % 100 + 50;
    } while (!is_prime(candidate));

    return candidate;
}

long long calculate_phi(long long p, long long q)
{
    return (p - 1) * (q - 1);
}

long long calculate_public_key(long long phi)
{
    long long public_key;

    do
    {
        public_key = rand() % (phi - 2) + 2;
    } while (gcd(public_key, phi) != 1);

    return public_key;
}

long long calculate_private_key(long long public_key, long long phi)
{
    long long private_key;

    for (long long d = 2; d < phi; ++d)
    {
        if ((public_key * d) % phi == 1)
        {
            private_key = d;
            break;
        }
    }

    return private_key;
}

long long encrypt(long long message, long long public_key, long long modulus)
{
    return mod_pow(message, public_key, modulus);
}

long long decrypt(long long cipher, long long private_key, long long modulus)
{
    return mod_pow(cipher, private_key, modulus);
}

int main()
{
    srand(time(0));

    long long p = generate_prime();
    long long q = generate_prime();

    long long n = p * q;
    long long phi = calculate_phi(p, q);

    long long public_key = calculate_public_key(phi);

    long long private_key = calculate_private_key(public_key, phi);

    cout << "Public Key (e, n): (" << public_key << ", " << n << ")\n";
    cout << "Private Key (d, n): (" << private_key << ", " << n << ")\n";

    long long message;
    cout << "Enter a message to encrypt: ";
    cin >> message;

    long long cipher = encrypt(message, public_key, n);
    cout << "Encrypted Message: " << cipher << endl;

    long long decrypted_message = decrypt(cipher, private_key, n);
    cout << "Decrypted Message: " << decrypted_message << endl;

    return 0;
}
