#include <iostream>
#include <queue>
using namespace std;

class Maze
{
public:
    int arr[9][9];

    struct Point
    {
        int x;
        int y;
        Point *parent;

        Point(int x, int y, Point *parent) : x(x), y(y), parent(parent) {}

        Point *getParent()
        {
            return parent;
        }

        string toString()
        {
            return "x = " + to_string(x) + " y = " + to_string(y);
        }
    };

    queue<Point *> q;

    Point *getPathBFS(int x, int y);

    bool isFree(int x, int y);

    void printMaze();

    void printPath(Point *p);
};

Maze::Point *Maze::getPathBFS(int x, int y)
{
    q.push(new Point(x, y, nullptr));

    while (!q.empty())
    {
        Point *p = q.front();
        q.pop();

        if (arr[p->x][p->y] == 9)
        {
            cout << "Exit is reached!" << endl;
            return p;
        }

        if (isFree(p->x + 1, p->y))
        {
            arr[p->x][p->y] = -1;
            Point *nextP = new Point(p->x + 1, p->y, p);
            q.push(nextP);
        }

        if (isFree(p->x - 1, p->y))
        {
            arr[p->x][p->y] = -1;
            Point *nextP = new Point(p->x - 1, p->y, p);
            q.push(nextP);
        }

        if (isFree(p->x, p->y + 1))
        {
            arr[p->x][p->y] = -1;
            Point *nextP = new Point(p->x, p->y + 1, p);
            q.push(nextP);
        }

        if (isFree(p->x, p->y - 1))
        {
            arr[p->x][p->y] = -1;
            Point *nextP = new Point(p->x, p->y - 1, p);
            q.push(nextP);
        }
    }
    return nullptr;
}

bool Maze::isFree(int x, int y)
{
    return (x >= 0 && x < sizeof(arr) / sizeof(arr[0]) &&
            y >= 0 && y < sizeof(arr[0]) / sizeof(arr[0][0]) &&
            (arr[x][y] == 0 || arr[x][y] == 9));
}

void Maze::printMaze()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void Maze::printPath(Point *p)
{
    while (p->getParent() != nullptr)
    {
        cout << p->toString() << endl;
        p = p->getParent();
    }
}

int main()
{
    Maze maze;
    Maze::Point *p = maze.getPathBFS(0, 0);

    maze.printMaze();

    if (p != nullptr)
    {
        maze.printPath(p);
    }

    return 0;
}
