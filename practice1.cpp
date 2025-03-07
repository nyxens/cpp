#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node* prev;
};
Node* createnode(int x){
    Node* newnode = new Node;
    newnode->value = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}
void insertnode(Node* &head,int position,int x){
    Node* newnode = createnode(x);
    if(position==0){
        newnode->next = head;
        if(head!=nullptr){//important to check
            head->prev = newnode;
        }
        head= newnode;
        return;
    }
    Node* temp = head;
    for(int i=0;i<position-1&&temp!=nullptr;i++){
        temp = temp->next;
    }
    if(temp==nullptr){
        cout << "Out Of Bounds!" << '\n';
        delete newnode;
        return;
    }
    newnode->next = temp->next;
    if(newnode->next!=nullptr)
        newnode->next->prev = newnode;//imp
    temp->next = newnode;
    newnode->prev = temp;
}
void deletenode(Node* &head,int position){
    if(head==nullptr){
        cout << "Empty Linked List!" << '\n';
        return;
    }
    if(position==0){
        Node* temp = head;
        head = temp->next;
        if(head!=nullptr){//imp
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    Node* temp = head;
    for(int i=0;i<position-1&&temp->next!=nullptr;i++){
        temp = temp->next;
    }
    if(temp->next==nullptr){
        cout << "Out Of List!" << '\n';
        return;
    }
    Node* delnode = temp->next;
    temp->next = delnode->next;
    if(delnode->next!=nullptr)//imp
        delnode->next->prev = temp;
    delete delnode;
}
void displayfront(Node* &head){
    if(head==nullptr){
        cout << "Empty List!" << '\n';
        return;
    }
    Node* temp = head;
    cout << "Head<->";
    while(temp!=nullptr){
        cout << temp->value << "<->";
        temp = temp->next;
    }
    cout << "Null" << '\n';
}
void displayback(Node* &head){
    if(head==nullptr){
        cout << "Empty List!" << '\n';
        return;
    }
    Node* temp = head;
    for(int i=0;temp->next!=nullptr;i++){
        temp = temp->next;
    }
    cout << "Null<->";
    while(temp!=nullptr){
        cout << temp->value << "<->";
        temp = temp->prev;
    }
    cout << "Head" << '\n';
}
int main(){
    Node* head = nullptr;
    insertnode(head,0,1);
    insertnode(head,1,2);
    insertnode(head,2,3);
    displayfront(head);
    displayback(head);
    return 0;
}