#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* last = nullptr;
void insertAtEnd(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(last == nullptr){
        last = newNode;
        last->next = last;
    }else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}
void display(){
    if(last == nullptr){
        cout << "List is empty!" << '\n';
        return;
    }
    Node* temp = last->next;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != last->next);
    cout << "HEAD" << '\n';
}
int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    return 0;
}
