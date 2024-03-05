#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    vector<int> coordinates;

    Point(const vector<int> &coords) : coordinates(coords) {}

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

struct KDNode
{
    Point point;
    KDNode *left;
    KDNode *right;

    KDNode(const Point &p) : point(p), left(nullptr), right(nullptr) {}
};

KDNode *buildKDTree(vector<Point> &points, size_t depth)
{
    if (points.empty())
    {
        return nullptr;
    }

    size_t k = points[0].coordinates.size();
    size_t axis = depth % k;

    auto medianIt = points.begin() + points.size() / 2;
    nth_element(points.begin(), medianIt, points.end(), [axis](const Point &a, const Point &b)
                { return a.coordinates[axis] < b.coordinates[axis]; });

    KDNode *root = new KDNode(*medianIt);
    root->left = buildKDTree(vector<Point>(points.begin(), medianIt), depth + 1);
    root->right = buildKDTree(vector<Point>(medianIt + 1, points.end()), depth + 1);

    return root;
}

bool searchKDTree(KDNode *root, const Point &target, size_t depth)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->point.coordinates == target.coordinates)
    {
        return true;
    }

    size_t k = target.coordinates.size();
    size_t axis = depth % k;

    if (target.coordinates[axis] < root->point.coordinates[axis])
    {
        return searchKDTree(root->left, target, depth + 1);
    }
    else
    {
        return searchKDTree(root->right, target, depth + 1);
    }
}

int main()
{

    vector<Point> points = {{{2, 3}}, {{5, 4}}, {{9, 6}}, {{4, 7}}, {{8, 1}}, {{7, 2}}};
    KDNode *root = buildKDTree(points, 0);

    Point target({5, 4});
    if (searchKDTree(root, target, 0))
    {
        cout << "Point found in KD-tree!" << endl;
    }
    else
    {
        cout << "Point not found in KD-tree." << endl;
    }

    return 0;
}
