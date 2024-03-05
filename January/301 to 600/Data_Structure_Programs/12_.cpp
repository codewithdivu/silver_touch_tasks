#include <iostream>
#include <vector>

using namespace std;

int minOperationsForPairing(int N, vector<int> &arr)
{
    vector<bool> visited(N, false);
    int minOperations = 0;

    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            int j = i;
            int cycleSize = 0;

            while (!visited[j])
            {
                visited[j] = true;
                j = arr[j];
                cycleSize++;
            }

            minOperations += (cycleSize - 1);
        }
    }

    return minOperations;
}

int main()
{

    int N1 = 2;
    vector<int> arr1 = {3, 0, 2, 1};
    cout << "Minimum operations for Example 1: " << minOperationsForPairing(N1, arr1) << endl;

    int N2 = 3;
    vector<int> arr2 = {1, 0, 3, 2, 4, 5};
    cout << "Minimum operations for Example 2: " << minOperationsForPairing(N2, arr2) << endl;

    return 0;
}
