#include <iostream>
using namespace std;
#define N 5
int queue[N];
int frontIndex = -1, rearIndex = -1;
void enqueue(int value) 
{
    if ((rearIndex + 1) % N == frontIndex) //if (rearindex == N-1)
        cout << "overflow!" << '\n';
    else 
    {
        if (frontIndex == -1) 
            frontIndex = 0;
        rearIndex = (rearIndex + 1) % N; //queue[++rearindex]value;
        queue[rearIndex] = value;
    }
}
void dequeue() 
{
    if (frontIndex == -1) 
        cout << "underflow!" << '\n';
    else 
    {
        if (frontIndex == rearIndex)
            frontIndex = rearIndex = -1;
        else 
            frontIndex = (frontIndex + 1) % N; //frontindex++;
    }
}
int front() 
{
    if (frontIndex == -1) 
        cout << "empty!" << '\n';
    else
    {   
        return queue[frontIndex];
    }
}
void display() 
{
    if (frontIndex == -1) 
        cout << "empty!" << '\n';
    else {
        cout << "Queue elements: ";
        int i = frontIndex;
        while (true)  //run till break
        {
            cout << queue[i] << " ";
            if (i == rearIndex)
                break;
            i = (i + 1) % N; //i++;
        }
        cout << '\n';
    }
}
void reverse() 
{
    if (frontIndex == -1) 
        return;
    int temp = front();
    dequeue();
    reverse();
    enqueue(temp);
}
int main() 
{
    int choice, value;
    do 
    {
        cout << '\n';
        cout << "Choose operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Reverse\n";
        cout << "5. Exit\n";
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
                reverse();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << '\n';
        }
    } while (choice != 5);
    return 0;
}