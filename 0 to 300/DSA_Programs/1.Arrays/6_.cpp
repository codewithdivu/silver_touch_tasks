#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5, 5};

    vector<int>::iterator ptr1 = arr.begin();
    vector<int>::iterator ptr2 = arr.begin() + 1;

    while (ptr2 != arr.end())
    {
        if (*ptr1 == *ptr2)
        {
            arr.erase(ptr2);
        }
        else
        {
            ptr1++;
            ptr2++;
        }
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}