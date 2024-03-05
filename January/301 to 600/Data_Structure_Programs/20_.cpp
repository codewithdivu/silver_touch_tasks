#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int rows, int cols)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

void findLongestRoute(vector<vector<int>> &matrix, int x, int y, int rows, int cols, int &maxRoute, int currentRoute)
{

    if (!isValid(x, y, rows, cols) || matrix[x][y] == 0)
    {
        return;
    }

    matrix[x][y] = 0;

    currentRoute++;

    maxRoute = max(maxRoute, currentRoute);

    findLongestRoute(matrix, x + 1, y, rows, cols, maxRoute, currentRoute);
    findLongestRoute(matrix, x - 1, y, rows, cols, maxRoute, currentRoute);
    findLongestRoute(matrix, x, y + 1, rows, cols, maxRoute, currentRoute);
    findLongestRoute(matrix, x, y - 1, rows, cols, maxRoute, currentRoute);

    matrix[x][y] = 1;
}

int longestRoute(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxRoute = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 1)
            {
                int currentRoute = 0;
                findLongestRoute(matrix, i, j, rows, cols, maxRoute, currentRoute);
            }
        }
    }

    return maxRoute;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
    };

    int result = longestRoute(matrix);

    cout << "The longest possible route in the matrix with hurdles is: " << result << endl;

    return 0;
}
