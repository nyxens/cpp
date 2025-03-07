#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
void enqueue(Node*& front,Node*& rear,int value){
    Node* newNode = createNode(value);
    if(rear == nullptr){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void dequeue(Node*& front,Node*& rear){
    if(front == nullptr){
        cout << "Queue is empty!" << '\n';
        return;
    }
    Node* temp = front;
    front = front->next;
    if(front == nullptr){
        rear = nullptr;
    }
    delete temp;
}
int peek(Node* front){
    if(front == nullptr){
        cout << "Queue is empty!" << '\n';
        return -1;
    }
    return front->data;
}
bool isEmpty(Node* front){
    return front == nullptr;
}
void display(Node* front){
    if(front == nullptr){
        cout << "Queue is empty!" << '\n';
        return;
    }
    Node* temp = front;
    while (temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << '\n';
}
int main(){
    Node* front = nullptr;
    Node* rear = nullptr;
    enqueue(front,rear,10);
    enqueue(front,rear,20);
    enqueue(front,rear,30);
    display(front);
    cout << "Front element: " << peek(front) << '\n';
    dequeue(front,rear);
    display(front);
    cout << "Front element: " << peek(front) << '\n';
    return 0;
}