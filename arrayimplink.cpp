// #include <iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
// };
// void insert(Node*& head,int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = nullptr;
//     if(head == nullptr){
//         head = newNode;
//     }else{
//         Node* temp = head;
//         while(temp->next != nullptr){
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }
// int get(Node* head,int index){
//     Node* temp = head;
//     int count = 0;
//     while(temp != nullptr){
//         if(count == index){
//             return temp->data;
//         }
//         count++;
//         temp = temp->next;
//     }
//     throw out_of_range("Index out of bounds");
// }
// void update(Node* head,int index,int value){
//     Node* temp = head;
//     int count = 0;
//     while(temp != nullptr){
//         if(count == index){
//             temp->data = value;
//             return;
//         }
//         count++;
//         temp = temp->next;
//     }
//     throw out_of_range("Index out of bounds");
// }
// void remove(Node*& head,int index){
//     if(head == nullptr){
//         throw out_of_range("List is empty");
//     }
//     if(index == 0){
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }
//     Node* temp = head;
//     for(int i = 0; i < index - 1 && temp->next != nullptr; i++){
//         temp = temp->next;
//     }
//     if(temp->next == nullptr){
//         throw out_of_range("Index out of bounds");
//     }
//     Node* nodeToDelete = temp->next;
//     temp->next = temp->next->next;
//     delete nodeToDelete;
// }
// void display(Node* head){
//     Node* temp = head;
//     while(temp != nullptr){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << '\n';
// }
// void freeList(Node*& head){
//     Node* temp;
//     while(head != nullptr){
//         temp = head;
//         head = head->next;
//         delete temp;
//     }
// }
// int main(){
//     Node* head = nullptr;
//     insert(head,10);
//     insert(head,20);
//     insert(head,30);
//     display(head);
//     cout << "Element at index 1: " << get(head,1) << '\n';
//     update(head,1,25);
//     display(head);
//     remove(head,1);
//     display(head);
//     freeList(head);
//     return 0;
// }