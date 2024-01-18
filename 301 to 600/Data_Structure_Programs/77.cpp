#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    vector<int> coordinates;

    Point(const vector<int>& coords) : coordinates(coords) {}
};

class KDTreeNode {
public:
    Point point;
    KDTreeNode* left;
    KDTreeNode* right;

    KDTreeNode(const Point& p) : point(p), left(nullptr), right(nullptr) {}
};

class KDTree {
private:
    KDTreeNode* root;

    KDTreeNode* buildTree(const vector<Point>& points, int depth) {
        if (points.empty()) {
            return nullptr;
        }

        int dimension = depth % points[0].coordinates.size();

        auto comparator = [dimension](const Point& a, const Point& b) {
            return a.coordinates[dimension] < b.coordinates[dimension];
        };

        auto median = points.begin() + points.size() / 2;
        nth_element(points.begin(), median, points.end(), comparator);

        KDTreeNode* node = new KDTreeNode(*median);
        node->left = buildTree(vector<Point>(points.begin(), median), depth + 1);
        node->right = buildTree(vector<Point>(median + 1, points.end()), depth + 1);

        return node;
    }

    void searchNearestNeighbor(KDTreeNode* node, const Point& target, int depth, KDTreeNode*& bestNode, double& bestDistance) const {
        if (!node) {
            return;
        }

        int dimension = depth % target.coordinates.size();
        double currentDistance = distance(node->point, target);

        if (currentDistance < bestDistance) {
            bestNode = node;
            bestDistance = currentDistance;
        }

        if (target.coordinates[dimension] < node->point.coordinates[dimension]) {
            searchNearestNeighbor(node->left, target, depth + 1, bestNode, bestDistance);
            if (target.coordinates[dimension] + bestDistance >= node->point.coordinates[dimension]) {
                searchNearestNeighbor(node->right, target, depth + 1, bestNode, bestDistance);
            }
        } else {
            searchNearestNeighbor(node->right, target, depth + 1, bestNode, bestDistance);
            if (target.coordinates[dimension] - bestDistance <= node->point.coordinates[dimension]) {
                searchNearestNeighbor(node->left, target, depth + 1, bestNode, bestDistance);
            }
        }
    }

    double distance(const Point& a, const Point& b) const {
        double result = 0.0;
        for (size_t i = 0; i < a.coordinates.size(); ++i) {
            result += pow(a.coordinates[i] - b.coordinates[i], 2);
        }
        return sqrt(result);
    }

public:
    KDTree(const vector<Point>& points) : root(nullptr) {
        root = buildTree(points, 0);
    }

    Point findNearestNeighbor(const Point& target) const {
        KDTreeNode* bestNode = nullptr;
        double bestDistance = numeric_limits<double>::infinity();
        searchNearestNeighbor(root, target, 0, bestNode, bestDistance);
        return (bestNode) ? bestNode->point : Point({});
    }
};

int main() {
    vector<Point> points = {{2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {7, 2}};
    KDTree kdTree(points);

    Point target({9, 2});
    Point nearestNeighbor = kdTree.findNearestNeighbor(target);

    cout << "Nearest neighbor to (" << target.coordinates[0] << ", " << target.coordinates[1]
              << ") is (" << nearestNeighbor.coordinates[0] << ", " << nearestNeighbor.coordinates[1] << ")\n";

    return 0;
}
