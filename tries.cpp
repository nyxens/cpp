#include <iostream>
#include <string>
using namespace std;
struct Node{
    int isEnd = 0;
    Node* children[26];
};
Node* createnode(){
    Node* newnode = new Node;
    newnode->isEnd = false;
    for(int i=0;i<26;i++){
        newnode->children[i] = NULL;
    }
    return newnode;
}
void insertion(Node* root,string s){
    Node* current = root;
    for(char c:s){
        if(current->children[c-'a']==NULL){
            current->children[c-'a'] = createnode();
        }
        current = current->children[c-'a'];
    }
    (current->isEnd)++;
}
void deletion(Node* root,string s){
    Node* current = root;
    for(char c:s){
        if(current->children[c-'a']==NULL){
            return;
        }
        current = current->children[c-'a'];
    }
    (current->isEnd)--;
}
int search(Node* root,string s){
    Node* current = root;
    for(char c:s){
        if(current->children[c-'a']==NULL){
            return false;
        }
        current = current->children[c-'a'];
    }
    return current->isEnd;
}
int main(){
    Node* root = createnode();
    insertion(root,"krishna");
    insertion(root,"krishna");
    cout << search(root,"krishna") << '\n';
    deletion(root,"krishna");
    cout << search(root,"krishna") << '\n';
    return 0;
}