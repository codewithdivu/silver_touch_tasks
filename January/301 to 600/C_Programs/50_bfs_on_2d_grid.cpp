#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell
{
    int row, col;

    Cell(int r, int c) : row(r), col(c) {}
};

bool isValid(int row, int col, int numRows, int numCols)
{
    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}

void bfs2DGrid(const vector<vector<char>> &grid, int startRow, int startCol)
{
    int numRows = grid.size();
    int numCols = grid[0].size();

    int rowMoves[] = {-1, 1, 0, 0};
    int colMoves[] = {0, 0, -1, 1};

    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    queue<Cell> q;

    q.push(Cell(startRow, startCol));
    visited[startRow][startCol] = true;

    while (!q.empty())
    {
        Cell current = q.front();
        q.pop();

        cout << "Visiting cell: (" << current.row << ", " << current.col << ")\n";

        for (int i = 0; i < 4; ++i)
        {
            int newRow = current.row + rowMoves[i];
            int newCol = current.col + colMoves[i];

            if (isValid(newRow, newCol, numRows, numCols) && !visited[newRow][newCol] &&
                grid[newRow][newCol] == 'O')
            {
                q.push(Cell(newRow, newCol));
                visited[newRow][newCol] = true;
            }
        }
    }
}

int main()
{

    vector<vector<char>> grid = {
        {'O', 'O', 'O', 'O', 'X'},
        {'O', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X', 'O'}};

    int startRow = 0;
    int startCol = 0;

    bfs2DGrid(grid, startRow, startCol);

    return 0;
}
