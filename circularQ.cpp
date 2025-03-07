#include <iostream>
using namespace std;
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front)
        cout << "overflow!";
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
        cout << "underflow!";
    else if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%N;
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
        cout << "empty";
    else
    {
        while (i != rear)
        {
            cout << queue[i];
            i=(i+1)%N;
            cout << " ";
        }
        cout << queue[rear];
    }
}
int main() 
{
    int choice, value;
    do {
        cout << '\n';
        cout << "Choose operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter data: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << '\n';
        }
    } while (choice != 4);

return 0;
}