#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int parallelBinarySearchRecursive(const vector<int>& arr, int target, int left, int right);

int parallelBinarySearch(const vector<int>& arr, int target) {
    int result = -1;

    #pragma omp parallel
    {
        #pragma omp single
        {
            result = parallelBinarySearchRecursive(arr, target, 0, arr.size() - 1);
        }
    }

    return result;
}

int parallelBinarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Element found
    } else if (arr[mid] < target) {
        int result = -1;

        #pragma omp task shared(result)
        {
            result = parallelBinarySearchRecursive(arr, target, mid + 1, right);
        }

        #pragma omp taskwait
        return result;
    } else {
        int result = -1;

        #pragma omp task shared(result)
        {
            result = parallelBinarySearchRecursive(arr, target, left, mid - 1);
        }

        #pragma omp taskwait
        return result;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int target = 7;

    int result = parallelBinarySearch(arr, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
