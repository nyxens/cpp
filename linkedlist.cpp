#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* createnode(int x){//returns pointer of newly created node to be used 
    node* newnode = new node;
    newnode->data=x;
    newnode->next=nullptr;
    return newnode;
}
void insertion(node* &head,int position,int x){
    node* newnode = createnode(x);//points to newly made node
    if(position==0){//insert at head
        newnode->next=head;//makes the next of the new node similar to head 
        head=newnode;//connects head to newnode(pointer)
        return;
    }
    node* temp = head;//temp is used for travesral
    for(int i=0;i<position-1&&temp!=nullptr;i++){//important
        temp=temp->next;//points temp to next node 
    }
    if(temp==nullptr){
        cout<<"out of position!"<<'\n';
        delete newnode;
        return;
    }
    newnode->next=temp->next;//connect newnode to position node
    temp->next=newnode;//connects previous node to new node
}
void deletion(node* &head,int position){
    if(head==nullptr){
        cout<<"empty list!"<<'\n';//nothing to delete
        return;
    }
    if(position==0){
        node* temp = head;//makes a temp pointer similar to head
        head = head->next;//shifts head pointer front
        delete temp;//delete node
        return;
    }
    node* temp = head;
    for(int i=0;i<position-1&&temp->next!=nullptr;i++){
        temp=temp->next;//move temp pointer until posiition-1
    }
    if(temp->next==nullptr){
        cout<<"position out of list!";//error
        return;
    }
    node* delnode = temp->next;//pointer delnode points to the node to be deleted
    temp->next=temp->next->next;//move temppointer to next
    delete delnode;//delete node
}
void display(node* head) {
    node* temp = head;
    cout << "HEAD->";
    while (temp!=nullptr){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << '\n';
}
int main(){
    node* head = nullptr;
    insertion(head,0,1);
    insertion(head,1,2);
    insertion(head,2,3);
    insertion(head,3,4);
    display(head);
    deletion(head,0);
    display(head);
}