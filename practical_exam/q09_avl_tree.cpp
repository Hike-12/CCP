// AVL Tree with LL, RR, LR, RL Rotations
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) { return n ? n->height : 0; }
int bf(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

void updateHeight(Node* n) {
    if (n) n->height = 1 + max(height(n->left), height(n->right));
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y; y->left = T2;
    updateHeight(y); updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x; x->right = T2;
    updateHeight(x); updateHeight(y);
    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)      root->left  = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;

    updateHeight(root);
    int b = bf(root);

    // LL rotation
    if (b > 1 && key < root->left->key) {
        cout << "LL rotation at " << root->key << "\n";
        return rotateRight(root);
    }
    // RR rotation
    if (b < -1 && key > root->right->key) {
        cout << "RR rotation at " << root->key << "\n";
        return rotateLeft(root);
    }
    // LR rotation
    if (b > 1 && key > root->left->key) {
        cout << "LR rotation at " << root->key << "\n";
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    // RL rotation
    if (b < -1 && key < root->right->key) {
        cout << "RL rotation at " << root->key << "\n";
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    for (int key : {10, 20, 30, 40, 50, 25}) {
        cout << "Inserting " << key << ": ";
        root = insert(root, key);
        if (root) cout << "(root=" << root->key << ")";
        cout << "\n";
    }
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\n";

    // Demonstrate LR/RL
    root = nullptr;
    cout << "\nLR/RL demo (insert 30, 10, 20):\n";
    for (int key : {30, 10, 20}) {
        cout << "Inserting " << key << ": ";
        root = insert(root, key);
        cout << "(root=" << root->key << ")\n";
    }
    cout << "Inorder: "; inorder(root); cout << "\n";
}
