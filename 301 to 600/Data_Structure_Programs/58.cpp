#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable {
private:
    vector<vector<int>> table;

public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int logn = static_cast<int>(log2(n)) + 1;

        table.resize(n, vector<int>(logn));

        
        for (int i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        
        for (int k = 1; (1 << k) <= n; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                table[i][k] = min(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    
    int query(int l, int r) {
        int k = static_cast<int>(log2(r - l + 1));
        return min(table[l][k], table[r - (1 << k) + 1][k]);
    }
};

int main() {
    
    vector<int> arr = {2, 6, 3, 1, 7, 4, 5};
    SparseTable st(arr);

    
    int result = st.query(2, 5);
    cout << "Minimum value in the range [2, 5]: " << result << endl;

    return 0;
}
