#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

double orientation(const Point &p, const Point &q, const Point &r)
{
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool isInside(const Point &p, const Point &q, const Point &r, const Point &test)
{
    return orientation(p, q, test) >= 0 && orientation(q, r, test) >= 0 && orientation(r, p, test) >= 0;
}

bool isLeft(const Point &p, const Point &q, const Point &test)
{
    return orientation(p, q, test) >= 0;
}

void seidelTriangulate(const vector<Point> &polygon)
{
    int n = polygon.size();

    if (n < 3)
    {
        cout << "Not a valid polygon." << endl;
        return;
    }

    vector<int> earTips;
    vector<bool> isEar(n, false);

    for (int i = 0; i < n; ++i)
    {
        int prev = (i - 1 + n) % n;
        int next = (i + 1) % n;

        if (isLeft(polygon[prev], polygon[i], polygon[next]))
        {
            earTips.push_back(i);
            isEar[i] = true;
        }
    }

    for (int i = 0; i < n - 3; ++i)
    {
        int earTipIndex = -1;

        for (int earIndex : earTips)
        {
            if (!isEar[earIndex])
                continue;

            int prev = (earIndex - 1 + n) % n;
            int next = (earIndex + 1) % n;

            bool isDiagonal = true;

            for (int j = 0; j < n; ++j)
            {
                if (j != prev && j != earIndex && j != next)
                {
                    if (isInside(polygon[prev], polygon[earIndex], polygon[next], polygon[j]))
                    {
                        isDiagonal = false;
                        break;
                    }
                }
            }

            if (isDiagonal)
            {
                earTipIndex = earIndex;
                break;
            }
        }

        cout << "Triangle: (" << polygon[(earTipIndex - 1 + n) % n].x << ", "
             << polygon[(earTipIndex - 1 + n) % n].y << ") - ("
             << polygon[earTipIndex].x << ", " << polygon[earTipIndex].y << ") - ("
             << polygon[(earTipIndex + 1) % n].x << ", "
             << polygon[(earTipIndex + 1) % n].y << ")" << endl;

        isEar[earTipIndex] = false;
        earTips.erase(remove(earTips.begin(), earTips.end(), earTipIndex), earTips.end());

        int prev = (earTipIndex - 1 + n) % n;
        int next = (earTipIndex + 1) % n;

        if (isLeft(polygon[prev], polygon[next], polygon[prev]))
        {
            earTips.push_back(prev);
            isEar[prev] = true;
        }

        if (isLeft(polygon[prev], polygon[next], polygon[next]))
        {
            earTips.push_back(next);
            isEar[next] = true;
        }
    }
}

int main()
{
    vector<Point> polygon = {{0, 0}, {2, 0}, {1, 1}, {0, 2}, {2, 2}};
    seidelTriangulate(polygon);

    return 0;
}
