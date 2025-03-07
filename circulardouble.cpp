#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head = nullptr;
void insertAtFront(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = newNode->prev = nullptr;
    if(head == nullptr){
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = newNode->prev = nullptr;
    if(head == nullptr){
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}
void displayForward(){
    if(head == nullptr){
        cout << "List is empty!" << '\n';
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "HEAD" << '\n';
}
void displayBackward(){
    if(head == nullptr){
        cout << "List is empty!" << '\n';
        return;
    }
    Node* temp = head->prev;
    do{
        cout << temp->data << " -> ";
        temp = temp->prev;
    }while(temp != head->prev);
    cout << "HEAD" << '\n';
}
int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    displayForward();
    displayBackward();
    return 0;
}
