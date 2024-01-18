#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    double distance(const Point& p) const {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct Edge {
    int to;
    double angle;

    Edge(int to, double angle) : to(to), angle(angle) {}

    bool operator<(const Edge& e) const {
        return angle < e.angle;
    }
};

const double EPS = 1e-8;
const int N = 1000;
const int K = 6;

int n;
vector<Point> points;
vector<vector<Edge>> yao_graph;

double get_angle(const Point& p, const Point& q) {
    double dx = q.x - p.x;
    double dy = q.y - p.y;
    if (dx < 0) {
        return atan2(-dy, -dx) + M_PI;
    } else if (dx > 0) {
        return atan2(dy, dx);
    } else {
        if (dy < 0) {
            return M_PI;
        } else {
            return 0;
        }
    }
}

void build_yao_graph() {
    for (int i = 0; i < n; i++) {
        vector<Edge> edges;
        for (int j = 0; j < K; j++) {
            double angle = (2 * M_PI / K) * j;
            int best_index = -1;
            double best_distance = numeric_limits<double>::max();
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                double d = points[k].distance(points[i]);
                double a = get_angle(points[i], points[k]);
                if (fabs(a - angle) < EPS) {
                    if (d < best_distance) {
                        best_distance = d;
                        best_index = k;
                    }
                }
            }
            if (best_index != -1) {
                edges.push_back(Edge(best_index, get_angle(points[i], points[best_index])));
            }
        }
        sort(edges.begin(), edges.end());
        yao_graph.push_back(edges);
    }
}

int main() {
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    yao_graph.assign(n, vector<Edge>());
    build_yao_graph();
    return 0;
}