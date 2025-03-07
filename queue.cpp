#include <iostream>
using namespace std;
#define N 5
int queue[N];
int frontIndex = -1, rearIndex = -1;
void enqueue(int value) 
{
    if ((rearIndex + 1) % N == frontIndex) //(if rearindex==N-1)
        cout << "overflow!" << '\n';
    else 
    {
        if (frontIndex == -1) 
            frontIndex = 0;
        rearIndex = (rearIndex + 1) % N; //queue[++rearindex]=value;
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
void front() 
{
    if (frontIndex == -1) 
        cout << "empty!" << '\n';
    else
        cout << queue[frontIndex] << '\n';
}
void isEmpty() 
{
    if (frontIndex == -1)
        cout << "empty!" << '\n';
    else
        cout << "Queue is not empty!" << '\n';
}
void isFull() 
{
    if ((rearIndex + 1) % N == frontIndex) //if(rearindex==N-1)
        cout << "full!" << '\n';
    else
        cout << "Queue is not full!" << '\n';
}
void size() 
{
    if (frontIndex == -1)
        cout << "Size is: 0" << '\n';
    else if (rearIndex >= frontIndex) //cout<< "size is : "<<(rearindex-frontindex+1)<<'\n';
        cout << "Size is: " << (rearIndex - frontIndex + 1) << '\n';
    else 
        cout << "Size is: " << (N - frontIndex + rearIndex + 1) << '\n';
}
void display() 
{
    if (frontIndex == -1) 
        cout << "empty!" << '\n';
    else {
        cout << "Queue elements: ";
        int i = frontIndex;
        while (true) 
        {
            cout << queue[i] << " ";
            if (i == rearIndex)
                break;
            i = (i + 1) % N; //i++;
        }
        cout << '\n';
    }
}

int main() 
{
    int choice, value;
    do 
    {
        cout << "Choose operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Check if empty\n";
        cout << "6. Check if full\n";
        cout << "7. Size\n";
        cout << "8. Exit\n";
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
                front();
                break;
            case 4:
                display();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                size();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << '\n';
        }
    } while (choice != 8);
    return 0;
}
