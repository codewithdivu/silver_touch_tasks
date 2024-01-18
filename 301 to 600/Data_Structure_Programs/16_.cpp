#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

// Structure to represent a point in K-dimensional space
struct Point
{
    vector<int> coordinates;

    Point(const vector<int> &coords) : coordinates(coords) {}

    // Function to calculate distance between two points
    int distance(const Point &other) const
    {
        int result = 0;
        for (size_t i = 0; i < coordinates.size(); ++i)
        {
            result += (coordinates[i] - other.coordinates[i]) * (coordinates[i] - other.coordinates[i]);
        }
        return result;
    }
};

// Structure to represent a node in the KD-tree
struct KDNode
{
    Point point;
    KDNode *left;
    KDNode *right;

    KDNode(const Point &p) : point(p), left(nullptr), right(nullptr) {}
};

// Function to build a KD-tree from a set of points
KDNode *buildKDTree(vector<Point> &points, size_t depth)
{
    if (points.empty())
    {
        return nullptr;
    }

    size_t k = points[0].coordinates.size();
    size_t axis = depth % k;

    // Sort points and choose the median as pivot
    auto medianIt = points.begin() + points.size() / 2;
    nth_element(points.begin(), medianIt, points.end(), [axis](const Point &a, const Point &b)
                { return a.coordinates[axis] < b.coordinates[axis]; });

    KDNode *root = new KDNode(*medianIt);
    Point medianPoint = *medianIt; // Make a copy
    root->left = buildKDTree(vector<Point>(points.begin(), medianIt), depth + 1);
    root->right = buildKDTree(vector<Point>(medianIt + 1, points.end()), depth + 1);

    return root;
}

// Function to search for the minimum value in a KD-tree
void searchMinKDTree(KDNode *root, const Point &target, size_t depth, int &minDistance, Point &minPoint)
{
    if (root == nullptr)
    {
        return;
    }

    int currentDistance = target.distance(root->point);

    if (currentDistance < minDistance)
    {
        minDistance = currentDistance;
        minPoint = root->point;
    }

    size_t k = target.coordinates.size();
    size_t axis = depth % k;

    // Check which subtree to search
    if (target.coordinates[axis] < root->point.coordinates[axis])
    {
        searchMinKDTree(root->left, target, depth + 1, minDistance, minPoint);
    }
    else
    {
        searchMinKDTree(root->right, target, depth + 1, minDistance, minPoint);
    }

    // Check the other subtree if necessary
    if (abs(target.coordinates[axis] - root->point.coordinates[axis]) < minDistance)
    {
        if (target.coordinates[axis] >= root->point.coordinates[axis])
        {
            searchMinKDTree(root->right, target, depth + 1, minDistance, minPoint);
        }
        else
        {
            searchMinKDTree(root->left, target, depth + 1, minDistance, minPoint);
        }
    }
}

int main()
{
    // Example usage
    vector<Point> points = {{{2, 3}}, {{5, 4}}, {{9, 6}}, {{4, 7}}, {{8, 1}}, {{7, 2}}};
    KDNode *root = buildKDTree(points, 0);

    Point target({6, 5});

    int minDistance = numeric_limits<int>::max();
    Point minPoint({});

    searchMinKDTree(root, target, 0, minDistance, minPoint);

    cout << "Minimum point: ";
    for (int coord : minPoint.coordinates)
    {
        cout << coord << " ";
    }
    cout << endl;

    return 0;
}
