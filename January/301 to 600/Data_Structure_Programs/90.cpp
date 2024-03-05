#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class SuffixTree {
private:
    struct Node {
        unordered_map<char, Node*> children;
        Node* suffixLink;
        int start;
        int* end;

        Node(int start, int* end) : start(start), end(end), suffixLink(nullptr) {}
    };

    Node* root;
    Node* activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixes;

    void extendSuffixTree(int pos) {
        
    }

public:
    
};

int main() {
  
    return 0;
}
