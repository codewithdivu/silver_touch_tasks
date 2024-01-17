#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;

    
    static bool comparePoints(const Point& p1, const Point& p2) {
        
        int crossProduct = (p2.y - p1.y) * (p2.x - p1.x) - (p2.x - p1.x) * (p2.y - p1.y);

        if (crossProduct == 0) {
            
            return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
        }

        return crossProduct > 0;
    }
};

class ConvexHull {
private:
    vector<Point> points;

public:
    ConvexHull(const vector<Point>& inputPoints) : points(inputPoints) {}

    
    vector<Point> findConvexHull() {
        int n = points.size();

        
        int pivot = 0;
        for (int i = 1; i < n; ++i) {
            if (points[i].y < points[pivot].y || (points[i].y == points[pivot].y && points[i].x < points[pivot].x)) {
                pivot = i;
            }
        }

        
        swap(points[0], points[pivot]);

        
        sort(points.begin() + 1, points.end(), Point::comparePoints);

        
        stack<Point> hull;
        hull.push(points[0]);
        hull.push(points[1]);
        hull.push(points[2]);

        
        for (int i = 3; i < n; ++i) {
            while (hull.size() > 1) {
                Point p2 = hull.top();
                hull.pop();
                Point p1 = hull.top();

                if (orientation(p1, p2, points[i]) != 2) {
                    hull.push(p2);
                    break;
                }
            }

            hull.push(points[i]);
        }

        
        vector<Point> convexHull;
        while (!hull.empty()) {
            convexHull.push_back(hull.top());
            hull.pop();
        }

        
        reverse(convexHull.begin(), convexHull.end());

        return convexHull;
    }

private:
    
    
    int orientation(const Point& p1, const Point& p2, const Point& p3) {
        int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

        if (val == 0) {
            return 0;
        }

        return (val > 0) ? 1 : 2;
    }
};

int main() {
    
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    ConvexHull convexHull(points);
    vector<Point> result = convexHull.findConvexHull();

    cout << "Convex Hull Points:" << endl;
    for (const Point& p : result) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
