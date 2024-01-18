#include <bits/stdc++.h>

template <typename Key, typename Value>
class CacheObliviousSearchTree {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        int size;

        Node(const Key& key, const Value& value, Node* left = nullptr, Node* right = nullptr)
            : key(key), value(value), left(left), right(right), size(1 + (left ? left->size : 0) + (right ? right->size : 0)) {}
    };

    Node* root;
    int block_size;

    static int get_block_size() {
        
        
    }

    static int get_subtree_size(Node* node) {
        
    }

    static Node* build_tree(const std::vector<std::pair<Key, Value>>& data) {
        
        
    }

    static Node* split(Node* node, const Key& key) {
        
        
    }

    static Node* merge(Node* left, Node* right) {
        
        
    }

    static Node* insert(Node* node, const std::pair<Key, Value>& data) {
        
        
    }

    static Node* remove(Node* node, const Key& key) {
        
        
    }

    static Node* search(Node* node, const Key& key) {
        
        
    }

public:
    CacheObliviousSearchTree() : root(nullptr), block_size(get_block_size()) {}

    void build(const std::vector<std::pair<Key, Value>>& data) {
        root = build_tree(data);
    }

    void insert(const std::pair<Key, Value>& data) {
        root = insert(root, data);
    }

    void remove(const Key& key) {
        root = remove(root, key);
    }

    Value search(const Key& key) {
        Node* node = search(root, key);
        if (node == nullptr) {
            throw std::out_of_range("Key not found");
        }
        return node->value;
    }
};