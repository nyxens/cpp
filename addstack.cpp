#include <iostream>
#include <string>
using namespace std;

#define N 100
int stack1[N], stack2[N], stack3[N];
int top1 = -1, top2 = -1, top3 = -1;

void push(int stack[], int &top, int value) {
    if (top == N - 1) {
        cout << "overflow" << "\n";
    } else {
        stack[++top] = value;
    }
}

int pop(int stack[], int &top) {
    if (top == -1) {
        cout << "underflow" << "\n";
        return -1;
    } else {
        return stack[top--];
    }
}

void addnum(string num1, string num2) {
    for (char digit : num1) {
        push(stack1, top1, digit - '0');
    }
    for (char digit : num2) {
        push(stack2, top2, digit - '0');
    }

    int carry = 0;
    while (top1 != -1 || top2 != -1 || carry != 0) {
        int digit1 = (top1 != -1) ? pop(stack1, top1) : 0;
        int digit2 = (top2 != -1) ? pop(stack2, top2) : 0;
        int sum = digit1 + digit2 + carry;
        push(stack3, top3, sum % 10);
        carry = sum / 10;
    }

    cout << "Result: ";
    while (top3 != -1) {
        cout << pop(stack3, top3);
    }
    cout << "\n";
}

int main() {
    string num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;

    addnum(num1, num2);

    return 0;
}