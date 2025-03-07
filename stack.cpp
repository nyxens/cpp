#include <iostream>
using namespace std;

#define N 5
int stack[N];
int top = -1;

void push(int value) {
    if (top == N - 1)
        cout << "Overflow!" << '\n';
    else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1)
        cout << "Underflow!" << '\n';
    else {
        int item = stack[top];
        top--;
        cout << "Popped: " << item << '\n';
    }
}

void peak() {
    if (top == -1)
        cout << "Underflow!" << '\n';
    else
        cout << "Top element: " << stack[top] << '\n';
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << '\n';
    } else {
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << '\n';
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is empty!" << '\n';
    else
        cout << "Stack is not empty!" << '\n';
}

void isFull() {
    if (top == N - 1)
        cout << "Stack is full!" << '\n';
    else
        cout << "Stack is not full!" << '\n';
}

void size() {
    cout << "Size is: " << top + 1 << '\n';
}

int main() {
    int choice, value;
    do {
        cout << "Choose operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peak\n";
        cout << "4. Display\n";
        cout << "5. Check if empty\n";
        cout << "6. Check if full\n";
        cout << "7. Size\n";
        cout << "8. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peak();
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