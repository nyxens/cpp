#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
node* createnode(int x){//returns pointer of newly created node to be used 
    node* newnode = new node;
    newnode->data=x;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    return newnode;
}
void inserthead(node* &head,int x){ 
    node* newnode = createnode(x);
    newnode->next=head; 
    if(head!=nullptr){
        head->prev=newnode;
    }
    head=newnode;
}
void inserttail(node* &head,int x){
    node* newnode = createnode(x);
    if(head==nullptr){ //directly point
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){ //traverse to tail
        temp=temp->next;
    }
    temp->next=newnode; //save
    newnode->prev=temp;
}
void insertion(node* &head,int position,int x){
    if (position == 0) { // Insert at head
        inserthead(head, x);
        return;
    }
    node* newnode = createnode(x);
    node* temp = head;
    for (int i=0;i<position-1&&temp!=nullptr;i++){ // traverse to pos-1
        temp = temp->next;
    }
    if(temp==nullptr){
        cout << "Position out of bounds!" << '\n';
        delete newnode;
        return;
    }
    newnode->next = temp->next; //connect newnode to position node
    newnode->prev = temp; //connects newnode to pos-1 node
    if(temp->next!=nullptr){
        temp->next->prev=newnode;
    }
    temp->next=newnode; //connects previous node to new node
}
void deletion(node* &head,int position){
    if(head==nullptr){
        cout << "List is empty!" << '\n';
        return;
    }
    if(position==0){ //delete at head
        node* temp = head;
        head=head->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }
        delete temp;
        return;
    }
    node* temp = head;
    for(int i=0;i<position&&temp!=nullptr;i++){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout << "Position out of bounds!" << '\n';
        return;
    }
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
    }
    if(temp->prev != nullptr){
        temp->prev->next = temp->next;
    }
    delete temp; //deletes node
}

void displayfront(node* head) {
    node* temp = head;
    cout << "HEAD<->";
    while (temp!=nullptr){   //the temp is updated to next->temp at the tail becomes null
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << '\n';
}
void displayback(node* head){
    if(head==nullptr){ //in main is null
        cout<<"empty";
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr){ //stops at tail as temp->next is null 
        temp=temp->next;
    }
    cout << "TAIL<->";
    while(temp!=nullptr){
        cout << temp->data << "<->";
        temp=temp->prev;
    }
    cout << "NULL" << '\n';
}
int main(){//insert at 3rd delete at fourth
    node* head = nullptr;
    insertion(head,0,1);
    insertion(head,1,2);
    insertion(head,2,3);
    insertion(head,3,4);
    insertion(head,4,5);
    displayfront(head);
    insertion(head,2,9);
    displayfront(head);
    deletion(head,3);
    displayfront(head);
    // inserthead(head,1);
    // insertion(head,1,2);
    // insertion(head,2,3);
    // insertion(head,3,4);
    // inserttail(head,5);
    // displayfront(head);
    // displayback(head);
    // deletion(head,0);
    // displayfront(head);
    // displayback(head);
}