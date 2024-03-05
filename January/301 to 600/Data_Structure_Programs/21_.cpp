#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Cell
{
    int x, y, distance;
};

bool isValid(int x, int y, int rows, int cols, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 && !visited[x][y]);
}

int shortestSafeRoute(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Cell> q;

    int startX, startY, endX, endY;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 2)
            {
                startX = i;
                startY = j;
            }
            else if (grid[i][j] == 3)
            {
                endX = i;
                endY = j;
            }
        }
    }

    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {

        Cell cell = q.front();
        q.pop();

        int x = cell.x;
        int y = cell.y;
        int distance = cell.distance;

        if (x == endX && y == endY)
        {
            return distance;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, rows, cols, grid, visited))
            {

                visited[newX][newY] = true;
                q.push({newX, newY, distance + 1});
            }
        }
    }

    return INT_MAX;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 3, 1},
    };

    int result = shortestSafeRoute(grid);

    if (result == INT_MAX)
    {
        cout << "No safe route exists." << endl;
    }
    else
    {
        cout << "The shortest safe route length is: " << result << endl;
    }

    return 0;
}
