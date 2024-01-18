#include <algorithm>
#include <iostream>

template <typename T>
class AvlTree {
private:
    struct Node {
        T value;
        int height;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* rotateLeft(Node* node) {
        Node* p = node->right;
        Node* q = p->left;

        p->left = node;
        node->right = q;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        p->height = std::max(height(p->left), height(p->right)) + 1;

        return p;
    }

    Node* rotateRight(Node* node) {
        Node* p = node->left;
        Node* q = p->right;

        p->right = node;
        node->left = q;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        p->height = std::max(height(p->left), height(p->right)) + 1;

        return p;
    }

    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value) {
            return rotateRight(node);
        }

        if (balance < -1 && value > node->right->value) {
            return rotateLeft(node);
        }

        if (balance > 1 && value > node->left->value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, const T& value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = remove(node->right, temp->value);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

public:
    AvlTree() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    bool search(const T& value) {
        Node* node = root;
        while (node != nullptr) {
            if (value < node->value) {
                node = node->left;
            } else if (value > node->value) {
                node = node->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void remove(const T& value) {
        root = remove(root, value);
    }
};




int main() {
    AvlTree<int> avlTree;

    
    avlTree.insert(50);
    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(70);
    avlTree.insert(60);
    avlTree.insert(80);

    
    std::cout << "Search for 20: " << (avlTree.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 100: " << (avlTree.search(100) ? "Found" : "Not Found") << std::endl;

    
    avlTree.remove(20);
    avlTree.remove(30);
    avlTree.remove(50);

    
    std::cout << "Search for 20 after removal: " << (avlTree.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 30 after removal: " << (avlTree.search(30) ? "Found" : "Not Found") << std::endl;

    return 0;
}