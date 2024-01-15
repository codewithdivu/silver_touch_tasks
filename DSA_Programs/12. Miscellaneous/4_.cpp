
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(const vector<int> &nums, int k)
{
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    return sorted_nums[k - 1];
}

int findKthLargest(const vector<int> &nums, int k)
{
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
    return sorted_nums[k - 1];
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int k = 3;
    int kthSmallest = findKthSmallest(nums, k);
    int kthLargest = findKthLargest(nums, k);

    cout << "Kth Smallest Element: " << kthSmallest << endl;
    cout << "Kth Largest Element: " << kthLargest << endl;

    return 0;
}
