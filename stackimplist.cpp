#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(Node*& top,int value){
    Node* newNode = new Node;
    if(!newNode){
        cout << "Stack overflow" << '\n';
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack" << '\n';
}
int pop(Node*& top){
    if(!top){
        cout << "Stack underflow" << '\n';
        return -1;
    }
    Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    return poppedValue;
}
int peek(Node* top){
    if(!top){
        cout << "Stack is empty" << '\n';
        return -1;
    }
    return top->data;
}
void display(Node* top){
    if(!top){
        cout << "Stack is empty" << '\n';
        return;
    }
    Node* temp = top;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}
int main(){
    Node* stack = nullptr;
    push(stack,10);
    push(stack,20);
    push(stack,30);
    display(stack);
    cout << "Top element is " << peek(stack) << '\n';
    cout << "Popped element is " << pop(stack) << '\n';
    display(stack);
    return 0;
}