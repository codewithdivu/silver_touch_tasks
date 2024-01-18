#include <iostream>
#include <vector>

using namespace std;

class DancingLinks {
private:
    struct Node {
        Node* left;
        Node* right;
        Node* up;
        Node* down;
        int row;
        int col;

        Node(int r, int c) : left(nullptr), right(nullptr), up(nullptr), down(nullptr), row(r), col(c) {}
    };

    vector<Node> nodes;
    vector<int> result;
    vector<int> colCount;

public:
    DancingLinks(int numRows, int numCols) {
        initializeNodes(numRows, numCols);
    }

    void addRow(const vector<int>& cols) {
        int rowHead = nodes.size();
        Node* prev = nullptr;

        for (int col : cols) {
            Node* newNode = new Node(rowHead, col);
            nodes.push_back(*newNode);

            if (prev == nullptr) {
                prev = newNode;
                newNode->left = newNode->right = newNode;
            } else {
                newNode->left = prev;
                newNode->right = prev->right;
                prev->right->left = newNode;
                prev->right = newNode;
                prev = newNode;
            }

            colCount[col]++;
        }
    }

    bool solve() {
        if (nodes.empty()) {
            return true; 
        }

        int col = chooseColumn();
        if (col == -1) {
            return false; 
        }

        coverColumn(col);

        Node* rowNode = nodes[col].down;
        while (rowNode != &nodes[col]) {
            result.push_back(rowNode->row);

            Node* rightNode = rowNode->right;
            while (rightNode != rowNode) {
                coverColumn(rightNode->col);
                rightNode = rightNode->right;
            }

            if (solve()) {
                return true;
            }

            result.pop_back();

            Node* leftNode = rowNode->left;
            while (leftNode != rowNode) {
                uncoverColumn(leftNode->col);
                leftNode = leftNode->left;
            }

            rowNode = rowNode->down;
        }

        uncoverColumn(col);
        return false;
    }

    void printSolution() const {
        for (int row : result) {
            cout << "Row " << row << ": ";
            Node* node = &nodes[row];
            do {
                cout << node->col << " ";
                node = node->right;
            } while (node != &nodes[row]);
            cout << endl;
        }
    }

private:
    void initializeNodes(int numRows, int numCols) {
        nodes.reserve(numRows * numCols + numCols + 1);
        colCount.resize(numCols + 1, 0);

        for (int i = 0; i <= numCols; ++i) {
            Node* newNode = new Node(0, i);
            nodes.push_back(*newNode);
        }

        for (int i = 1; i <= numRows; ++i) {
            for (int j = 1; j <= numCols; ++j) {
                Node* newNode = new Node(i, j);
                nodes.push_back(*newNode);
            }
        }

        for (int j = 1; j <= numCols; ++j) {
            nodes[j].left = &nodes[j - 1];
            nodes[j].right = &nodes[j + 1];
            nodes[j].up = nodes[j].down = &nodes[j];
        }

        nodes[0].left = &nodes[numCols];
        nodes[0].right = &nodes[1];
    }

    int chooseColumn() const {
        int minCol = -1;
        int minSize = numeric_limits<int>::max();

        for (int col = nodes[0].right->col; col != 0; col = nodes[col].right->col) {
            if (colCount[col] < minSize) {
                minSize = colCount[col];
                minCol = col;
            }
        }

        return minCol;
    }

    void coverColumn(int col) {
        nodes[col].left->right = nodes[col].right;
        nodes[col].right->left = nodes[col].left;

        Node* rowNode = nodes[col].down;
        while (rowNode != &nodes[col]) {
            Node* rightNode = rowNode->right;
            while (rightNode != rowNode) {
                rightNode->up->down = rightNode->down;
                rightNode->down->up = rightNode->up;
                colCount[rightNode->col]--;
                rightNode = rightNode->right;
            }
            rowNode = rowNode->down;
        }
    }

    void uncoverColumn(int col) {
        Node* rowNode = nodes[col].up;
        while (rowNode != &nodes[col]) {
            Node* leftNode = rowNode->left;
            while (leftNode != rowNode) {
                leftNode->up->down = leftNode;
                leftNode->down->up = leftNode;
                colCount[leftNode->col]++;
                leftNode = leftNode->left;
            }
            rowNode = rowNode->up;
        }

        nodes[col].left->right = &nodes[col];
        nodes[col].right->left = &nodes[col];
    }
};

int main() {
    
    const int N = 8;
    const int numRows = N * N;
    const int numCols = 6 * N - 2;
    
    DancingLinks dlx(numRows, numCols);

    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            vector<int> cols;
            cols.push_back(i * N + j);                
            cols.push_back(N * N + i * N + j);         
            cols.push_back(2 * N * N + i + j);         
            cols.push_back(4 * N * N - 2 + i - j);     
            dlx.addRow(cols);
        }
    }

    dlx.solve();
    dlx.printSolution();

    return 0;
}
