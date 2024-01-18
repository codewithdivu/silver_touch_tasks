#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallelPrefixSum(vector<int> &input)
{
    int n = input.size();

#pragma omp parallel
    {
        int numThreads = omp_get_num_threads();
        int threadID = omp_get_thread_num();

        for (int stride = 1; stride < n; stride *= 2)
        {
#pragma omp for
            for (int i = 2 * stride - 1; i < n; i += 2 * stride)
            {
                input[i] += input[i - stride];
            }
#pragma omp barrier
        }

#pragma omp for
        for (int i = 1; i < n; ++i)
        {
            input[i] += input[i - 1];
        }
    }
}

int main()
{

    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Input array: ";
    for (int num : input)
    {
        cout << num << " ";
    }
    cout << endl;

    parallelPrefixSum(input);

    cout << "Prefix sum array: ";
    for (int num : input)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
