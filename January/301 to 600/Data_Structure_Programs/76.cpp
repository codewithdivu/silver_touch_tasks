#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

class LayeredRangeTree
{
public:
    struct Node
    {
        int key;
        vector<Point> points;
        Node *left;
        Node *right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *buildTree(vector<Point> &points, int dimension)
    {
        if (points.empty())
        {
            return nullptr;
        }

        int mid = points.size() / 2;
        auto compare = (dimension == 0) ? [](const Point &a, const Point &b)
        { return a.x < b.x; }
                                        : [](const Point &a, const Point &b)
        { return a.y < b.y; };
        nth_element(points.begin(), points.begin() + mid, points.end(), compare);

        Node *node = new Node(points[mid].x);
        node->points = points;

        node->left = buildTree(vector<Point>(points.begin(), points.begin() + mid), 1 - dimension);
        node->right = buildTree(vector<Point>(points.begin() + mid + 1, points.end()), 1 - dimension);

        return node;
    }

    void rangeQuery(Node *node, int x1, int x2, int y1, int y2, int dimension, vector<Point> &result)
    {
        if (!node)
        {
            return;
        }

        if (x1 <= node->key && node->key <= x2)
        {
            auto it = lower_bound(
                node->points.begin(), node->points.end(), Point(x1, y1),
                (dimension == 0) ? [](const Point &a, const Point &b)
                    { return a.x < b.x; }
                                 : [](const Point &a, const Point &b)
                    { return a.y < b.y; });

            while (it != node->points.end() && it->x <= x2 && it->y >= y1 && it->y <= y2)
            {
                result.push_back(*it);
                ++it;
            }
        }

        if (dimension == 0)
        {
            if (x1 <= node->key)
            {
                rangeQuery(node->left, x1, x2, y1, y2, 1 - dimension, result);
            }
            if (node->key <= x2)
            {
                rangeQuery(node->right, x1, x2, y1, y2, 1 - dimension, result);
            }
        }
        else
        {
            if (y1 <= node->key)
            {
                rangeQuery(node->left, x1, x2, y1, y2, 1 - dimension, result);
            }
            if (node->key <= y2)
            {
                rangeQuery(node->right, x1, x2, y1, y2, 1 - dimension, result);
            }
        }
    }

public:
    LayeredRangeTree(vector<Point> &points)
    {
        root = buildTree(points, 0);
    }

    vector<Point> query(int x1, int x2, int y1, int y2)
    {
        vector<Point> result;
        rangeQuery(root, x1, x2, y1, y2, 0, result);
        return result;
    }
};

int main()
{
    vector<Point> points = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};
    LayeredRangeTree layeredRangeTree(points);

    // Query for points in the range [2, 5]x[3, 7]
    vector<Point> result = layeredRangeTree.query(2, 5, 3, 7);

    // Display the result
    for (const auto &point : result)
    {
        cout << "(" << point.x << ", " << point.y << ") ";
    }

    return 0;
}
