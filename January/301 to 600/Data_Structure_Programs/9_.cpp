#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMaxSoldiers(int N, vector<vector<int>> &arr)
{
    unordered_map<int, int> teamCount;

    for (const auto &pair : arr)
    {
        teamCount[pair[0]]++;
        teamCount[pair[1]]++;
    }

    int maxSoldiers = 0;
    for (const auto &count : teamCount)
    {
        maxSoldiers = max(maxSoldiers, count.second);
    }

    return maxSoldiers;
}

int main()
{
    
    int N1 = 4;
    vector<vector<int>> arr1 = {{1, 2}, {2, 3}, {2, 4}, {2, 5}};
    cout << "Maximum soldiers in a team: " << findMaxSoldiers(N1, arr1) << endl;

    int N2 = 8;
    vector<vector<int>> arr2 = {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {6, 7}, {7, 8}, {7, 9}, {7, 10}};
    cout << "Maximum soldiers in a team: " << findMaxSoldiers(N2, arr2) << endl;

    int N3 = 3;
    vector<vector<int>> arr3 = {{1, 2}, {2, 3}, {3, 1}};
    cout << "Maximum soldiers in a team: " << findMaxSoldiers(N3, arr3) << endl;

    return 0;
}