#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;
    
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        
        return y;
    }
    
    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        } else {
            return node; // Duplicate values not allowed
        }
        
        // Update height
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        
        // Get balance factor
        int balance = getBalance(node);
        
        // LL Rotation
        if (balance > 1 && val < node->left->data) {
            cout << "LL Rotation at " << node->data << endl;
            return rightRotate(node);
        }
        
        // RR Rotation
        if (balance < -1 && val > node->right->data) {
            cout << "RR Rotation at " << node->data << endl;
            return leftRotate(node);
        }
        
        // LR Rotation
        if (balance > 1 && val > node->left->data) {
            cout << "LR Rotation at " << node->data << endl;
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // RL Rotation
        if (balance < -1 && val < node->right->data) {
            cout << "RL Rotation at " << node->data << endl;
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    void inorderHelper(Node* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    bool isBalancedHelper(Node* node) {
        if (node == nullptr) return true;
        
        int balance = getBalance(node);
        if (balance < -1 || balance > 1) return false;
        
        return isBalancedHelper(node->left) && isBalancedHelper(node->right);
    }
    
public:
    AVLTree() : root(nullptr) {}
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    void inorder() {
        cout << "\nInorder Traversal: ";
        inorderHelper(root);
        cout << endl;
    }
    
    bool isBalanced() {
        return isBalancedHelper(root);
    }
};

int main() {
    AVLTree avl;
    
    cout << "=== AVL Tree Insertion ===" << endl;
    int values[] = {50, 25, 75, 10, 30, 60, 80, 5, 15};
    int n = sizeof(values) / sizeof(values[0]);
    
    cout << "Inserting values: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    cout << endl << endl;
    
    for (int i = 0; i < n; i++) {
        avl.insert(values[i]);
    }
    
    avl.inorder();
    
    cout << "\nHeight-Balance Check: ";
    if (avl.isBalanced()) {
        cout << "Tree is Height-Balanced" << endl;
    } else {
        cout << "Tree is NOT Height-Balanced" << endl;
    }
    
    return 0;
}
