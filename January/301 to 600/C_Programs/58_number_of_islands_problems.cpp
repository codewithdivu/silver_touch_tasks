#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col)
{
    int numRows = grid.size();
    int numCols = grid[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] == '0')
    {
        return;
    }

    grid[row][col] = '0';

    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int numRows = grid.size();
    if (numRows == 0)
    {
        return 0;
    }

    int numCols = grid[0].size();
    int islandCount = 0;

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            if (grid[i][j] == '1')
            {

                islandCount++;
                dfs(grid, i, j);
            }
        }
    }

    return islandCount;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int result = numIslands(grid);

    cout << "Number of Islands: " << result << endl;

    return 0;
}
