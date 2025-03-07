#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find and print the widest level
void printWidestLevel(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    int maxWidth = 0;  // To track the maximum width
    vector<int> widestLevel;  // To store elements of the widest level
    
    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        vector<int> currentLevel; // Store elements at this level
        
        // Traverse all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            Node* temp = q.front();
            q.pop();
            currentLevel.push_back(temp->data);
            
            // Enqueue left and right children
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        
        // Update maxWidth and store the level if it's the widest so far
        if (levelSize > maxWidth) {
            maxWidth = levelSize;
            widestLevel = currentLevel;
        }
    }

    // Print the widest level
    cout << "Widest Level (Width = " << maxWidth << "): ";
    for (int val : widestLevel) {
        cout << val << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    /* Constructing the following tree:
            1
           / \
          2   3
         / \   \
        4   5   6
       / \
      7   8
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);

    printWidestLevel(root);
    return 0;
}