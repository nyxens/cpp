#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createnode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left =nullptr;
    newNode->right = nullptr;
    return newNode;
}
Node* insertion(Node* root,int x){
    if(root == nullptr){
        return createnode(x);
    }
    char choice;
    cout << "Insert " <<x<< " to L or R of " <<root->data<< ": ";
    cin >> choice;
    if(choice == 'L'){
        if(root->left == nullptr){
            root->left = createnode(x);
        }else{
           root->left = insertion(root->left,x);
        }
    }else if(choice == 'R'){
        if(root->right == nullptr){
            root->right = createnode(x);
        }else{
            root->right = insertion(root->right,x);  
        }
    }else{
        cout << "Invalid input!\n";
    }
    return root;
}
void inorder(Node* root){
    if(root == nullptr) 
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void mirror(Node* root){
    if (root == nullptr)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
Node* LCA(Node* root,int n1,int n2){
    if(root == nullptr)
        return nullptr;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* leftLCA = LCA(root->left,n1,n2);
    Node* rightLCA = LCA(root->right,n1,n2);
    if(leftLCA && rightLCA)
        return root;
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}
int main(){
    Node* root = nullptr;
    int n,value;
    cout << "Enter number of nodes to insert: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter value to insert: ";
        cin >> value;
        root = insertion(root, value);
    }
    cout << "Inorder: ";
    inorder(root);
    cout << '\n';
    mirror(root);
    cout << "Inorder: ";
    inorder(root);
    cout << '\n';
    int n1, n2;
    cout << "Enter two nodes to find LCA: ";
    cin >> n1 >> n2;
    Node* lca = LCA(root,n1,n2);
    if(lca != nullptr){
        cout << lca->data << '\n';
    }else{
        cout << "No LCA" << '\n';
    }
    return 0;
}