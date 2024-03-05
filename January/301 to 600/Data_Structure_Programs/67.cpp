#include <iostream>
#include <vector>
#include <deque>

using namespace std;


struct Line {
    long long m, b;

    long long eval(long long x) const {
        return m * x + b;
    }
};

class ConvexHullTrick {
private:
    deque<Line> lines;

    
    bool isIntersectionLeft(const Line &line1, const Line &line2, const Line &line3) {
        return (line2.b - line1.b) * (line1.m - line3.m) >= (line3.b - line1.b) * (line1.m - line2.m);
    }

public:
    
    void addLine(long long m, long long b) {
        Line newLine = {m, b};

        
        while (lines.size() >= 2 && !isIntersectionLeft(lines[lines.size() - 2], lines.back(), newLine)) {
            lines.pop_back();
        }

        lines.push_back(newLine);
    }

    
    long long query(long long x) {
        while (lines.size() >= 2 && lines[0].eval(x) <= lines[1].eval(x)) {
            lines.pop_front();
        }

        return lines.front().eval(x);
    }
};

int main() {
    ConvexHullTrick cht;

    
    cht.addLine(1, 2);
    cht.addLine(2, 5);
    cht.addLine(-1, -1);

    cout << "Maximum value at x=3: " << cht.query(3) << endl;

    return 0;
}
