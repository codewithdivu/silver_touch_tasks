#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class WaveletTree {
private:
    vector<vector<int>> tree;
    vector<int> alphabet;

    
    void constructTree(const vector<int>& arr, int start, int end, int depth) {
        if (start >= end || depth >= tree.size()) {
            return;
        }

        int mid = (alphabet[depth] + 1) / 2;

        auto midIter = partition(arr.begin() + start, arr.begin() + end,
                                 [mid](int c) { return c < mid; });

        int midIndex = midIter - arr.begin();

        tree[depth][midIndex] = 1; 

        
        constructTree(arr, start, midIndex, depth + 1);
        constructTree(arr, midIndex, end, depth + 1);
    }

public:
    WaveletTree(const vector<int>& arr, int alphabetSize) {
        tree.resize(alphabetSize, vector<int>(arr.size() + 1, 0));
        alphabet.resize(alphabetSize);

        
        iota(alphabet.begin(), alphabet.end(), 0);

        
        constructTree(arr, 0, arr.size(), 0);
    }

    
    int rangeQuery(int l, int r, int c) {
        int result = 0;

        for (int depth = 0; depth < tree.size(); ++depth) {
            int mid = (alphabet[depth] + 1) / 2;

            if (c < mid) {
                
                r = tree[depth][r] - tree[depth][l];
                l = tree[depth][l];
            } else {
                
                r = r - tree[depth][r];
                l = l - tree[depth][l];
            }
        }

        return result;
    }
};

int main() {
    
    vector<int> input = {2, 5, 1, 3, 4, 2, 5, 3};
    int alphabetSize = *max_element(input.begin(), input.end()) + 1;

    WaveletTree wt(input, alphabetSize);

    
    int count = wt.rangeQuery(2, 6, 3);
    cout << "Occurrences of character 3 in the range [2, 6]: " << count << endl;

    return 0;
}
