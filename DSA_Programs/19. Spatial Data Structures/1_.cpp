#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Point
{
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class Rectangle
{
public:
    double x, y, width, height;

    Rectangle(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}

    bool contains(const Point &point) const
    {
        return (point.x >= x && point.x < x + width && point.y >= y && point.y < y + height);
    }

    bool intersects(const Rectangle &other) const
    {
        return (x < other.x + other.width && x + width > other.x &&
                y < other.y + other.height && y + height > other.y);
    }
};

class QuadtreeNode
{
public:
    static const int MAX_CAPACITY = 4;

    Rectangle bounds;
    vector<Point> points;
    vector<QuadtreeNode *> children;

    QuadtreeNode(const Rectangle &bounds) : bounds(bounds) {}

    ~QuadtreeNode()
    {
        for (QuadtreeNode *child : children)
        {
            delete child;
        }
    }

    bool isLeaf() const
    {
        return children.empty();
    }

    void subdivide()
    {
        double subWidth = bounds.width / 2.0;
        double subHeight = bounds.height / 2.0;
        double x = bounds.x;
        double y = bounds.y;

        children.push_back(new QuadtreeNode(Rectangle(x, y, subWidth, subHeight)));
        children.push_back(new QuadtreeNode(Rectangle(x + subWidth, y, subWidth, subHeight)));
        children.push_back(new QuadtreeNode(Rectangle(x, y + subHeight, subWidth, subHeight)));
        children.push_back(new QuadtreeNode(Rectangle(x + subWidth, y + subHeight, subWidth, subHeight)));
    }

    int getIndex(const Point &point) const
    {
        int index = -1;
        double verticalMidpoint = bounds.x + bounds.width / 2.0;
        double horizontalMidpoint = bounds.y + bounds.height / 2.0;

        // Check in which quadrant the point lies
        bool topQuadrant = (point.y < horizontalMidpoint && point.y >= bounds.y);
        bool bottomQuadrant = (point.y >= horizontalMidpoint && point.y < bounds.y + bounds.height);

        if (point.x < verticalMidpoint && point.x >= bounds.x)
        {
            if (topQuadrant)
            {
                index = 1; // Top left
            }
            else if (bottomQuadrant)
            {
                index = 2; // Bottom left
            }
        }
        else if (point.x >= verticalMidpoint && point.x < bounds.x + bounds.width)
        {
            if (topQuadrant)
            {
                index = 0; // Top right
            }
            else if (bottomQuadrant)
            {
                index = 3; // Bottom right
            }
        }

        return index;
    }

    void insert(const Point &point)
    {
        if (isLeaf() && points.size() < MAX_CAPACITY)
        {
            points.push_back(point);
        }
        else
        {
            if (isLeaf())
            {
                subdivide();
            }

            int index = getIndex(point);
            if (index != -1)
            {
                children[index]->insert(point);
            }
        }
    }

    vector<Point> queryRange(const Rectangle &range) const
    {
        vector<Point> pointsInRange;

        if (!bounds.intersects(range))
        {
            return pointsInRange;
        }

        for (const Point &point : points)
        {
            if (range.contains(point))
            {
                pointsInRange.push_back(point);
            }
        }

        if (!isLeaf())
        {
            for (QuadtreeNode *child : children)
            {
                vector<Point> childPoints = child->queryRange(range);
                pointsInRange.insert(pointsInRange.end(), childPoints.begin(), childPoints.end());
            }
        }

        return pointsInRange;
    }
};

class Quadtree
{
private:
    QuadtreeNode *root;

public:
    Quadtree(const Rectangle &bounds) : root(new QuadtreeNode(bounds)) {}

    ~Quadtree()
    {
        delete root;
    }

    void insert(const Point &point)
    {
        root->insert(point);
    }

    vector<Point> queryRange(const Rectangle &range) const
    {
        return root->queryRange(range);
    }
};

int main()
{
    Rectangle bounds(0, 0, 100, 100);
    Quadtree quadtree(bounds);

    // Insert some points into the Quadtree
    for (int i = 0; i < 20; ++i)
    {
        quadtree.insert(Point(rand() % 100, rand() % 100));
    }

    // Query points within a range
    Rectangle queryRange(25, 25, 50, 50);
    vector<Point> pointsInRange = quadtree.queryRange(queryRange);

    // Print the points within the range
    cout << "Points within the range:" << endl;
    for (const Point &point : pointsInRange)
    {
        cout << "(" << point.x << ", " << point.y << ")" << endl;
    }

    return 0;
}
