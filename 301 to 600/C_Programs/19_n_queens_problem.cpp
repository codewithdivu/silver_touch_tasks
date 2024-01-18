#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NQueens
{
private:
    int boardSize;
    vector<vector<string>> solutions;

public:
    NQueens(int n) : boardSize(n) {}

    vector<vector<string>> solveNQueens()
    {
        vector<string> board(boardSize, string(boardSize, '.'));

        solve(0, board);

        return solutions;
    }

private:
    void solve(int row, vector<string> &board)
    {
        if (row == boardSize)
        {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < boardSize; ++col)
        {
            if (isSafe(row, col, board))
            {
                board[row][col] = 'Q';
                solve(row + 1, board);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, const vector<string> &board)
    {
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < boardSize; --i, ++j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
};

void printSolutions(const vector<vector<string>> &solutions)
{
    for (const auto &solution : solutions)
    {
        for (const string &row : solution)
        {
            cout << row << endl;
        }
        cout << "-----------------" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    NQueens nQueensProblem(n);
    vector<vector<string>> solutions = nQueensProblem.solveNQueens();

    cout << "Number of solutions: " << solutions.size() << endl;

    printSolutions(solutions);

    return 0;
}
