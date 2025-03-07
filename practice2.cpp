#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
};
Node* createnode(int x){
    Node* newnode = new Node;
    newnode->value = x;
    newnode->next = nullptr;
    return newnode;
}
void insertnode(Node* &head,int position,int x){
    Node* newnode = createnode(x);
    if(position==0){
        newnode->next= head;
        head = newnode;
        return;
    }
    Node* temp = head;
    for(int i=0;i<position-1&&temp!=nullptr;i++){
        temp = temp->next;
    }
    if(temp==nullptr){
        cout << "position out of bounds!";
        delete newnode;
        return;
    }
    newnode->next = temp->next;
    temp->next=newnode;
}
void deletenode(Node* &head, int position){
    if(head==nullptr){
        cout << "Empty list!";
        return;
    }
    if(position==0){
        Node* temp= head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for(int i=0;i<position-1&&temp->next!=nullptr;i++){
        temp = temp->next;
    }
    if(temp->next==nullptr){
        cout << "out of list!";
        return;
    }
    Node* delnode = temp->next;
    temp->next=temp->next->next;
    delete delnode;
}
void display(Node* &head){
    Node* temp = head;
    cout << "HEAD->";
    while(temp!=nullptr){
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
int main(){
    Node* head = nullptr;
    insertnode(head,0,1);
    insertnode(head,1,2);
    insertnode(head,2,3);
    insertnode(head,3,4);
    display(head);
    deletenode(head,0);
    display(head);
}