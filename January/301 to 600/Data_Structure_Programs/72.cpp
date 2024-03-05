#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FractionalCascading {
private:
    vector<vector<int>> arrays;
    vector<vector<int>> auxiliary;

    void preprocess() {
        auxiliary.resize(arrays.size());

        for (size_t i = 0; i < arrays.size(); ++i) {
            auxiliary[i].resize(arrays[i].size());
            preprocessAuxiliary(i, 0, arrays[i].size() - 1);
        }
    }

    void preprocessAuxiliary(int arrayIndex, int left, int right) {
        if (left == right) {
            auxiliary[arrayIndex][left] = left;
        } else {
            int mid = (left + right) / 2;
            preprocessAuxiliary(arrayIndex, left, mid);
            preprocessAuxiliary(arrayIndex, mid + 1, right);

            int i = left;
            int j = mid + 1;
            while (i <= mid && j <= right) {
                if (arrays[arrayIndex][i] <= arrays[arrayIndex][j]) {
                    auxiliary[arrayIndex][i] = j;
                    ++i;
                } else {
                    ++j;
                }
            }

            while (i <= mid) {
                auxiliary[arrayIndex][i] = right + 1;
                ++i;
            }
        }
    }

public:
    FractionalCascading(const vector<vector<int>>& inputArrays) : arrays(inputArrays) {
        preprocess();
    }

    
    int binarySearch(int target) const {
        int result = 0;

        for (size_t i = 0; i < arrays.size(); ++i) {
            int index = lower_bound(arrays[i].begin(), arrays[i].end(), target) - arrays[i].begin();
            if (index == arrays[i].size() || arrays[i][index] > target) {
                --index;
            }

            result += auxiliary[i][index];
        }

        return result;
    }
};

int main() {
    vector<vector<int>> inputArrays = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {3, 5, 7, 9}
    };

    FractionalCascading fc(inputArrays);

    
    int target = 5;
    int result = fc.binarySearch(target);

    cout << "Number of elements less than or equal to " << target << ": " << result << endl;

    return 0;
}
