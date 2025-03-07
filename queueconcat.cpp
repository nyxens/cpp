#include <iostream>
#define N 100
using namespace std;
int front1 = -1, rear1 = -1,front2 = -1, rear2 = -1;
int queue1[N],queue2[N];
bool isEmpty(int front, int rear) {
    return front == -1;
}
bool isFull(int rear) {
    return rear == N - 1;
}
void enqueue(int queue[], int &front, int &rear, int value) {
    if (isFull(rear)) {
        cout << "Queue overflow!\n";
        return;
    }
    if (isEmpty(front, rear))
        front = 0;
    queue[++rear] = value;
}
int dequeue(int queue[], int &front, int &rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue underflow!\n";
        return -1;
    }
    int value = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}
void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << '\n';
}
void concatenate() {
    while (!isEmpty(front2, rear2)) {
        enqueue(queue1, front1, rear1, dequeue(queue2, front2, rear2));
    }
}

int main() {
    cout << "Enqueueing elements into the first queue:\n";
    enqueue(queue1, front1, rear1, 10);
    enqueue(queue1, front1, rear1, 20);
    enqueue(queue1, front1, rear1, 30);
    display(queue1, front1, rear1);
    cout << "Enqueueing elements into the second queue:\n";
    enqueue(queue2, front2, rear2, 40);
    enqueue(queue2, front2, rear2, 50);
    enqueue(queue2, front2, rear2, 60);
    display(queue2, front2, rear2);
    cout << "Concatenating second queue to the first queue:\n";
    concatenate();
    display(queue1, front1, rear1);
    return 0;
}
