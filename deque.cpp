#include <iostream>
using namespace std;
#define N 5
int deque[N];
int front=-1,rear=-1;
bool isFull(){
    return (front==0&&rear==N-1)||(front==rear+1);
}
bool isEmpty(){
    return front==-1;
}
void enqueuefront(int x){
    if(isFull()){
        cout<<"full!\n";
        return;
    }
    if(isEmpty())
        front=rear=0;
    else if(front==0)
        front=N-1;
    else
        front--;
    deque[front]=x;
}
void enqueuerear(int x){
    if(isFull()){
        cout<<"full!\n";
        return;
    }
    if(isEmpty())
        front=rear=0;
    else if(rear==N-1)
        rear=0;
    else
        rear++;
    deque[rear]=x;
}
void dequeuefront(){
    if(isEmpty()){
        cout<<"empty!\n";
        return;
    }
    if(front==rear)
        front=rear=-1;
    else if(front==N-1)
        front=0;
    else
        front++;
}
void dequeuerear(){
    if(isEmpty()){
        cout<<"empty!\n";
        return;
    }
    if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=N-1;
    else
        rear--;
}
void display(){
    if(isEmpty()){
        cout<<"empty!\n";
        return;
    }
    if(front<=rear)
        for(int i=front;i<=rear;i++)
            cout<<deque[i]<<" ";
    else{
        for(int i=front;i<N;i++)
            cout<<deque[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<deque[i]<<" ";
    }
    cout<<"\n";
}
int main() 
{
    int choice, value;
    do {
        cout << "Choose operation:\n";
        cout << "1. Enqueuefront\n";
        cout << "2. Enqueuerear\n";
        cout << "3. Dequeuefront\n";
        cout << "4. Dequeuerear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter data: ";
                cin >> value;
                enqueuefront(value);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> value;
                enqueuerear(value);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << '\n';
        }
    }while(choice != 6);
    return 0;
}