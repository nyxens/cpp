#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    int rightheight = 0;
    int leftheight = 0;
};
void inorder(Node* root){
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int leftheight(Node* node){
    if (node == nullptr) {
        return 0;
    }
    return node->leftheight;
}
int rightheight(Node* node){
    if (node == nullptr) {
        return 0;
    }
    return node->rightheight;
}
int maximum(int a, int b){
    return a > b ? a : b;
}
Node* create(){
    int x;
    cout << "Enter data to be inserted (-1 to stop creating node)" << '\n';
    cin >> x;
    if (x == -1) {
        return nullptr;
    } else {
        Node* node = new Node();
        node->data = x;
        cout << " left child of " << x << ":\n ";
        node->left = create();
        cout << " right child of " << x << " :\n";
        node->right = create();
        node->leftheight = maximum(leftheight(node->left), rightheight(node->left)) + 1;
        node->rightheight = maximum(leftheight(node->right), rightheight(node->right)) + 1;
        return node;
    }
}
void printWidestLevel(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    int maxWidth = 0;  // To track the maximum width
    vector<int> widestLevel;  // To store elements of the widest level
    
    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        vector<int> currentLevel; // Store elements at this level
        
        for (int i = 0; i < levelSize; i++) {
            Node* temp = q.front();
            q.pop();
            currentLevel.push_back(temp->data);
            
            // Enqueue left and right children
            if (temp->left) 
                q.push(temp->left);
            if (temp->right)    
                q.push(temp->right);
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
int main(){
    Node* node = create();
    cout << "\n";
    printWidestLevel(node);
    return 0;
}