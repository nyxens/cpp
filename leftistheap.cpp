#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* right = nullptr;
    Node* left = nullptr;
    int svalue = 1;
};
void inorder(Node* root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int minimum(int a,int b){
    return a < b ? a : b;
}
int svalue(Node* node){
    if(node == nullptr){
        return 0;
    }
    return node->svalue;
}
Node* merge(Node* root1,Node* root2){
    if(root1 == nullptr){
        return root2;
    }
    if(root2 == nullptr){
        return root1;
    }
    if(root1->data > root2->data){
        swap(root1, root2);
    }
    root1->right = merge(root1->right, root2);
    if(svalue(root1->left) < svalue(root1->right)){
        swap(root1->left, root1->right);
    }
    root1->svalue = svalue(root1->right) + 1;
    return root1;
}
int searchMin(Node* root){
    if(root == nullptr){
        cout << "empty";
    }
    return root->data;
}
Node* insert(Node* root,int x){
    Node* node = new Node();
    node->data = x;
    node->svalue = 1;
    return merge(root, node);
}
Node* deletetion(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* left = root->left;
    Node* right = root->right;
    delete root;
    return merge(left, right);
}
int main(){
    Node* root = nullptr;
    root = insert(root,10);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,7);
    root = insert(root,6);
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,1);
    cout << "Inorder of leftist heap: ";
    inorder(root);
    cout << endl;
    cout << "Minimum element: " << searchMin(root) << endl;
    root = deletetion(root);
    cout << "Inorder of leftist heap: ";
    inorder(root);
    cout << endl;
    return 0;
}