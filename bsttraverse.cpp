#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
};
Node* createnode(int x){
    Node* newNode = new Node();
    newNode->key = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node* insertion(Node* root,int x){
    if(root == nullptr){
        return createnode(x);
    }
    if(x < root->key){
        root->left = insertion(root->left,x);
    }else if(x > root->key){
        root->right = insertion(root->right,x);
    }
    return root;
}
Node* insuc(Node* root){
    while (root->left != nullptr){
        root = root->left;
    }
    return root;
}
Node* deletion(Node* root,int x){
    if(root == nullptr){
        return root;
    }
    if(x < root->key){
        root->left = deletion(root->left,x);
    }else if(x > root->key){
        root->right = deletion(root->right,x);
    }else{
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = insuc(root->right);
        root->key = temp->key;
        root->right = deletion(root->right,temp->key);
    }
    return root;
}
void inorder(Node* root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void inorderNR(Node* root){
    if(root != nullptr){
    stack <Node*> stack;
    Node* current = root;
    while(current != nullptr||!stack.empty()){
        while(current != nullptr){
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        cout << current->key << " ";
        current = current->right;
        }
    }
}
int main(){
    Node* root = nullptr;
    root = insertion(root,10);
    root = insertion(root,5);
    root = insertion(root,20);
    cout << "Inorder : ";
    inorder(root);
    cout << '\n';
    cout << "Inorder NR : ";
    inorderNR(root);
    cout << '\n';
    return 0;
} 