#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

class VanEmdeBoasTree {
private:
    int universeSize;
    int min;
    int max;
    VanEmdeBoasTree* summary;
    vector<VanEmdeBoasTree*> cluster;

    int high(int x) {
        return static_cast<int>(floor(x / sqrt(universeSize)));
    }

    int low(int x) {
        return x % static_cast<int>(sqrt(universeSize));
    }

    int index(int x, int y) {
        return x * static_cast<int>(sqrt(universeSize)) + y;
    }

public:
    VanEmdeBoasTree(int u) : universeSize(u) {
        if (u == 2) {
            min = max = -1;
            summary = nullptr;
            cluster.resize(0);
        } else {
            min = numeric_limits<int>::max();
            max = numeric_limits<int>::min();
            summary = new VanEmdeBoasTree(static_cast<int>(sqrt(u)));
            cluster.resize(static_cast<size_t>(sqrt(u)), nullptr);
        }
    }

    int minimum() const {
        return min;
    }

    int maximum() const {
        return max;
    }

    bool contains(int x) const {
        if (x == min || x == max) {
            return true;
        } else if (universeSize == 2) {
            return false;
        } else if (cluster[high(x)]) {
            return cluster[high(x)]->contains(low(x));
        } else {
            return false;
        }
    }

    void insert(int x) {
        if (min == max) {
            min = max = x;
        } else {
            if (x < min) {
                swap(x, min);
            }
            if (x > max) {
                max = x;
            }

            if (cluster[high(x)] == nullptr) {
                cluster[high(x)] = new VanEmdeBoasTree(static_cast<int>(sqrt(universeSize)));
                summary->insert(high(x));
            }

            cluster[high(x)]->insert(low(x));
        }
    }

    void remove(int x) {
        if (min == max) {
            min = numeric_limits<int>::max();
            max = numeric_limits<int>::min();
        } else if (universeSize == 2) {
            (x == 0) ? (min = 1) : (min = 0);
            max = min;
        } else if (cluster[high(x)]) {
            cluster[high(x)]->remove(low(x));

            if (cluster[high(x)]->minimum() == numeric_limits<int>::max()) {
                summary->remove(high(x));

                if (x == max) {
                    int summaryMax = summary->maximum();
                    if (summaryMax == -1) {
                        max = min;
                    } else {
                        max = index(summaryMax, cluster[summaryMax]->maximum());
                    }
                }
            } else if (x == max) {
                max = index(high(x), cluster[high(x)]->maximum());
            }
        }
    }
};

int main() {
    VanEmdeBoasTree vEBTree(16);

    vEBTree.insert(2);
    vEBTree.insert(3);
    vEBTree.insert(14);
    vEBTree.insert(8);

    cout << "Minimum: " << vEBTree.minimum() << endl; // Output: 2
    cout << "Maximum: " << vEBTree.maximum() << endl; // Output: 14
    cout << "Contains 8? " << boolalpha << vEBTree.contains(8) << endl; // Output: true

    vEBTree.remove(8);

    cout << "Contains 8 after removal? " << boolalpha << vEBTree.contains(8) << endl; // Output: false

    return 0;
}
