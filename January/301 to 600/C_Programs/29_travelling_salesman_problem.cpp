#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point
{
    double x, y;
};

double calculateDistance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double calculateTotalDistance(const vector<Point> &cities, const vector<int> &path)
{
    double totalDistance = 0.0;
    int n = path.size();

    for (int i = 0; i < n - 1; ++i)
    {
        totalDistance += calculateDistance(cities[path[i]], cities[path[i + 1]]);
    }

    // Return to the starting city
    totalDistance += calculateDistance(cities[path[n - 1]], cities[path[0]]);

    return totalDistance;
}

void printPath(const vector<int> &path)
{
    cout << "Optimal Path: ";
    for (int city : path)
    {
        cout << city << " ";
    }
    cout << endl;
}

void tspBruteForce(const vector<Point> &cities)
{
    int n = cities.size();
    vector<int> path(n);
    for (int i = 0; i < n; ++i)
    {
        path[i] = i;
    }

    double minDistance = numeric_limits<double>::infinity();

    do
    {
        double currentDistance = calculateTotalDistance(cities, path);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            printPath(path);
            cout << "Total Distance: " << minDistance << endl;
        }
    } while (next_permutation(path.begin() + 1, path.end()));
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<Point> cities(n);
    cout << "Enter the coordinates of each city:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "City " << i << ": ";
        cin >> cities[i].x >> cities[i].y;
    }

    tspBruteForce(cities);

    return 0;
}
