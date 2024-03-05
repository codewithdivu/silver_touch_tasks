#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class SqrtDecomposition {
private:
    vector<int> blocks;
    vector<int> lazy;
    int blockSize;
    int size;

public:
    SqrtDecomposition(const vector<int>& values) {
        size = values.size();
        blockSize = sqrt(size);
        blocks.resize(ceil((double)size / blockSize));
        lazy.resize(blocks.size(), 0);

        build(values);
    }

    void update(int left, int right, int delta) {
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock) {
            for (int i = left; i <= right; ++i) {
                blocks[startBlock] += delta;
            }
        } else {
            for (int i = left; i < (startBlock + 1) * blockSize; ++i) {
                blocks[startBlock] += delta;
            }

            for (int i = startBlock + 1; i < endBlock; ++i) {
                lazy[i] += delta;
            }

            for (int i = endBlock * blockSize; i <= right; ++i) {
                blocks[endBlock] += delta;
            }
        }
    }

    int query(int left, int right) {
        int result = 0;
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock) {
            for (int i = left; i <= right; ++i) {
                result += blocks[startBlock] + lazy[startBlock];
            }
        } else {
            for (int i = left; i < (startBlock + 1) * blockSize; ++i) {
                result += blocks[startBlock] + lazy[startBlock];
            }

            for (int i = startBlock + 1; i < endBlock; ++i) {
                result += blocks[i] + lazy[i];
            }

            for (int i = endBlock * blockSize; i <= right; ++i) {
                result += blocks[endBlock] + lazy[endBlock];
            }
        }

        return result;
    }

private:
    void build(const vector<int>& values) {
        for (int i = 0; i < size; ++i) {
            blocks[i / blockSize] += values[i];
        }
    }
};

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SqrtDecomposition sqrtDecomp(values);

    cout << "Sum in range [2, 6]: " << sqrtDecomp.query(2, 6) << endl;

    sqrtDecomp.update(3, 7, 2);

    cout << "Sum in range [2, 6] after update: " << sqrtDecomp.query(2, 6) << endl;

    return 0;
}
