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
Node* insucc(Node* root){
    if(root == nullptr)
        return nullptr;
    while(root->left!=nullptr){
        root = root->left;
    }
    return root;
}
Node* deletion(Node* root,int key){
    if(root == nullptr)
        return root;
    if (key < root->data) {
        root->left = deletion(root->left,key);
    }else if(key > root->data){
        root->right = deletion(root->right,key);
    }else{
        if(root->left == nullptr&&root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = insucc(root->right);
            root->data = temp->data; 
            root->right = deletion(root->right, temp->data); 
        }
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
void preorder(Node* root){
    if(root == nullptr) 
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){

    if(root == nullptr) 
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int depth(Node* root){

    if(root == nullptr)
        return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
int maxvalue(Node* root){
    if(root == nullptr)
        return -1;
    int maxValue = root->data;
    int leftMax = maxvalue(root->left);
    int rightMax = maxvalue(root->right);
    if(leftMax>maxValue)
        maxValue = leftMax;
    if(rightMax>maxValue)
        maxValue = rightMax;
    return maxValue;
}
int main(){
    Node* root = nullptr;
    int n,value;
    cout << "Enter number of nodes to insert: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter value to insert: ";
        cin >> value;
        root = insertion(root,value);
    }
    cout << "Inorder : ";
    inorder(root);
    cout << '\n';
    cout << "Depth :" << depth(root) << '\n';
    cout << "Max Value :" << maxvalue(root) << '\n';
    return 0;
} 