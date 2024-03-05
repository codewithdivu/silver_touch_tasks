#include <iostream>
#include <vector>

using namespace std;

int countRangeSum(vector<long long> &nums, int lower, int upper)
{
    int count = 0;
    int n = nums.size();

    // Compute the prefix sum array
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    // Helper function to merge two sorted arrays and count the valid subarrays
    auto mergeAndCount = [&](int left, int mid, int right) -> int
    {
        int count = 0;
        int j = mid + 1;
        int k = mid + 1;

        for (int i = left; i <= mid; ++i)
        {
            // Count the number of subarrays in the right half whose sum is in the range [prefixSum[i] - upper, prefixSum[i] - lower]
            while (j <= right && prefixSum[j] - prefixSum[i] < lower)
            {
                ++j;
            }
            while (k <= right && prefixSum[k] - prefixSum[i] <= upper)
            {
                ++k;
            }
            count += k - j;
        }

        // Merge the two sorted arrays
        vector<long long> merged(right - left + 1);
        int i = left;
        j = mid + 1;
        int mergedIndex = 0;

        while (i <= mid || j <= right)
        {
            if (i > mid)
            {
                merged[mergedIndex++] = prefixSum[j++];
            }
            else if (j > right)
            {
                merged[mergedIndex++] = prefixSum[i++];
            }
            else
            {
                if (prefixSum[i] < prefixSum[j])
                {
                    merged[mergedIndex++] = prefixSum[i++];
                }
                else
                {
                    merged[mergedIndex++] = prefixSum[j++];
                }
            }
        }

        // Copy the merged array back to the original array
        for (int i = 0; i < merged.size(); ++i)
        {
            prefixSum[left + i] = merged[i];
        }

        return count;
    };

    // Function declaration for mergeSortAndCount
    function<int(int, int)> mergeSortAndCount;

    // Definition of mergeSortAndCount
    mergeSortAndCount = [&](int left, int right) -> int
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = mergeSortAndCount(left, mid) + mergeSortAndCount(mid + 1, right) + mergeAndCount(left, mid, right);
            return count;
        }
        return 0;
    };

    // Perform merge sort and count the valid subarrays
    count = mergeSortAndCount(0, n);

    return count;
}

int main()
{
    // Example usage
    vector<long long> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;

    int result = countRangeSum(nums, lower, upper);

    // Print the result
    cout << "Number of subarrays with sum in the range [" << lower << ", " << upper << "]: " << result << endl;

    return 0;
}
