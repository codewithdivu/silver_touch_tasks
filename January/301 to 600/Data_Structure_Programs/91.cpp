#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class WaveletMatrix {
private:
    vector<vector<int>> matrix;
    vector<int> sortedSeq;

public:
    WaveletMatrix(const vector<int>& sequence) {
        int maxValue = *max_element(sequence.begin(), sequence.end());
        matrix.resize(maxValue + 1, vector<int>(sequence.size() + 1, 0));
        sortedSeq = sequence;

        buildWaveletMatrix(0, sequence.size(), 0, maxValue);
    }

    int rank(int x, int i) {
        int result = 0;
        for (int level = 0; level < matrix.size(); ++level) {
            result += matrix[level][i];
            if (x >= matrix[level].size()) {
                i = 0; // Move to the left child
            } else {
                i = matrix[level][i];
            }
        }
        return result;
    }

    int kthSmallest(int k) {
        int left = 0, right = matrix.size() - 1;
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int count = matrix[mid].back() - matrix[mid][k];
            
            if (count >= k) {
                result = mid;
                right = mid - 1;
            } else {
                k -= count;
                left = mid + 1;
            }
        }

        return result;
    }

private:
    void buildWaveletMatrix(int left, int right, int level, int maxValue) {
        if (left == right || level > maxValue) {
            return;
        }

        int mid = (left + right) / 2;
        auto isLeft = [&](int x) { return x <= mid; };

        for (int i = left; i < right; ++i) {
            matrix[level][i + 1] = matrix[level][i] + isLeft(sortedSeq[i]);
        }

        int leftIdx = left, rightIdx = mid;
        for (int i = left; i < right; ++i) {
            if (isLeft(sortedSeq[i])) {
                sortedSeq[leftIdx++] = sortedSeq[i];
            } else {
                sortedSeq[rightIdx++] = sortedSeq[i];
            }
        }

        buildWaveletMatrix(left, mid, level + 1, maxValue);
        buildWaveletMatrix(mid, right, level + 1, maxValue);
    }
};

int main() {
    vector<int> sequence = {2, 1, 3, 4, 2, 5};
    WaveletMatrix waveletMatrix(sequence);

    int x = 2, i = 4;
    cout << "Rank of " << x << " at index " << i << ": " << waveletMatrix.rank(x, i) << endl;

    int k = 3;
    cout << "The " << k << "-th smallest element is: " << waveletMatrix.kthSmallest(k) << endl;

    return 0;
}
