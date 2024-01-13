#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {4, 9, 5};
    vector<int> arr2 = {9, 4, 9, 8, 4};

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    set<int> s;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            s.insert(arr1[i]);
            i++;
            j++;
        }
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
