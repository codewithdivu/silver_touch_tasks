#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char str[n];
    cin >> str;

    bool check = 1;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            check = 0;
            break;
        }
    }

    if (check == true)
    {
        cout << "word is pallindrome" << endl;
    }
    else
    {
        cout << "not pallindrome" << endl;
    }

    return 0;
}