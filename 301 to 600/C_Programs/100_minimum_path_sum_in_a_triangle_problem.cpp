#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();

    for (int i = rows - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {

            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle[0][0];
}

int main()
{

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    int result = minimumTotal(triangle);

    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}
