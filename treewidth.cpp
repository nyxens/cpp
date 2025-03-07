#include <iostream>
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
void print(Node* root, int level){
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        print(root->left, level - 1);
        print(root->right, level - 1);
    }
}
int getWidth(Node* root, int level){
    if (root == nullptr) {
        return 0;
    }
    if (level == 1) {
        return 1;
    } else if (level > 1) {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
    return 0;
}
void printW(Node* root){
    int maxWidth = 0;
    int maxLevel = 0;
    int width;
    int h = maximum(leftheight(root), rightheight(root));
    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth) {
            maxWidth = width;
            maxLevel = i;
        }
    }
    cout << "width : ";
    print(root,maxLevel);
    cout << '\n';
}
int main(){
    Node* node = create();
    cout << "Inorder: ";
    inorder(node);
    cout << "\n";
    printW(node);
    return 0;
}