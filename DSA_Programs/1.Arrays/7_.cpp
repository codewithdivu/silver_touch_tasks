#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {1, 2, 3, 3, 4, 5, 6};
    vector<int> arr2 = {3, 4, 5, 6, 7, 8};
    vector<int> answer;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            answer.push_back(arr1[i++]);
        }
        else if (arr2[j] < arr1[i])
        {
            answer.push_back(arr2[j++]);
        }
    }

    while (i < arr1.size())
    {
        answer.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        answer.push_back(arr2[j++]);
    }

    for (auto it : answer)
    {
        cout << it << " ";
    }

    return 0;
}