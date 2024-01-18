#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, vector<vector<int>> &ans, int index, vector<int> output)
{

    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subsets(arr, ans, index + 1, output);

    // include
    int element = arr[index];
    output.push_back(element);
    subsets(arr, ans, index + 1, output);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    subsets(arr, ans, index, output);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}