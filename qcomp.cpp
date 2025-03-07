#include <iostream>
using namespace std;
#define N 5
int queue1[N], queue2[N];
int frontIndex1=-1,rearIndex1=-1,frontIndex2=-1,rearIndex2=-1;
void enqueue(int queue[],int &frontIndex,int &rearIndex,int value) 
{
    if((rearIndex+1)%N==frontIndex) 
        cout << "Overflow!" << '\n';
    else 
    {
        if(frontIndex == -1) 
            frontIndex = 0;
        rearIndex=(rearIndex+1)%N;
        queue[rearIndex]=value;
    }
}
void dequeue(int queue[],int &frontIndex,int &rearIndex) 
{
    if(frontIndex==-1) 
        cout << "Underflow!" << '\n';
    else 
    {
        if(frontIndex == rearIndex)
            frontIndex=rearIndex=-1;
        else 
            frontIndex=(frontIndex+1)%N;
    }
}
void display(int queue[],int frontIndex,int rearIndex) 
{
    if(frontIndex==-1) 
        cout << "empty!" << '\n';
    else 
    {
        cout << "Queue elements: ";
        int i = frontIndex;
        while (true) 
        {
            cout << queue[i] << " ";
            if (i == rearIndex)
                break;
            i = (i+1)%N;
        }
        cout << '\n';
    }
}
bool check(int queue1[],int frontIndex1,int rearIndex1,int queue2[],int frontIndex2,int rearIndex2) 
{
    if ((rearIndex1-frontIndex1+N)%N != (rearIndex2-frontIndex2+N)%N)
        return false;
    int i = frontIndex1,j = frontIndex2;
    while (i != rearIndex1||j != rearIndex2) 
    {
        if(queue1[i] != queue2[j])
            return false;
        i = (i + 1) % N;
        j = (j + 1) % N;
    }
    return queue1[rearIndex1] == queue2[rearIndex2];
}
void choose(int queue[],int &frontIndex,int &rearIndex) 
{
    int choice, value;
    do 
    {
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
                enqueue(queue,frontIndex,rearIndex,value);
                break;
            case 2:
                dequeue(queue,frontIndex,rearIndex);
                break;
            case 3:
                display(queue,frontIndex,rearIndex);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << '\n';
        }
    } while (choice != 4);
}
int main() 
{
    cout << "Queue 1:\n";
    choose(queue1, frontIndex1, rearIndex1);
    cout << "\nQueue 2:\n";
    choose(queue2, frontIndex2, rearIndex2);
    if (check(queue1, frontIndex1, rearIndex1, queue2, frontIndex2, rearIndex2))
        cout << "\nThe two queues are identical.\n";
    else
        cout << "\nThe two queues are not identical.\n";
    return 0;
}