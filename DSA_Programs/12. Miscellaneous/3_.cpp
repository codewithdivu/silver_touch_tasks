#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// first approach
int majority(vector<int> arr)
{
    map<int, int> mp;
    for (int i : arr)
    {
        mp[i]++;
    }

    for (auto it : mp)
    {
        if (it.second > arr.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// second approach (Boyer-Moore Voting algorithm)
int findMajorityElement(vector<int> &nums)
{
    int candidate = 0;
    int count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }

        count += (num == candidate) ? 1 : -1;
    }

    count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    if (count > nums.size() / 2)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    cout << "Majority element is " << majority(arr) << endl;
    cout << "Majority element is " << findMajorityElement(arr) << endl;
    return 0;
}
