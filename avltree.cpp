#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of a node
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// Function to right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to balance the tree
Node* balance(Node* node) {
    // Update height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balanceFactor = getBalance(node);

    // Left Heavy
    if (balanceFactor > 1) {
        if (getBalance(node->left) >= 0) {
            // Left-Left Case
            return rightRotate(node);
        } else {
            // Left-Right Case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    // Right Heavy
    if (balanceFactor < -1) {
        if (getBalance(node->right) <= 0) {
            // Right-Right Case
            return leftRotate(node);
        } else {
            // Right-Left Case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    // Return the unchanged node if balanced
    return node;
}

// Function to insert a node in the AVL tree
Node* insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicate keys are not allowed
        return node;

    // 2. Balance the tree
    return balance(node);
}

// Function to find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // 1. Perform standard BST delete
    if (root == nullptr){
        cout << "element does not exsit";
        return root;
    }

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node, return
    if (root == nullptr)
        return root;

    // 2. Balance the tree
    return balance(root);
}

// Function to print the tree in-order
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    cout << "In-order traversal of the AVL tree: ";
    inOrder(root);
    cout << endl;

    deleteNode(root,20);

    cout << "In-order traversal after deletion of 30: ";
    inOrder(root);
    cout << endl;

    return 0;
}