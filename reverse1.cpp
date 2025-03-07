#include <iostream>
using namespace std;
#define N 100
char stack1[N];
char stack2[N];
int top1=-1, top2=-1;
void push(char stack[], int &top, char value) 
{
    if (top == N - 1)
        cout << "Overflow!" << '\n';
    else 
    {
        top++;
        stack[top] = value;
    }
}
char pop(char stack[], int &top) 
{
    if (top == -1) 
    {
        cout << "Underflow!" << '\n';
        return '\0';
    } 
    else 
    {
        char item = stack[top];
        top--;
        return item;
    }
}
void reverse() 
{
    while (top1 != -1)
    {
        push(stack2, top2, pop(stack1, top1));
    }
    for (int i = 0; i <= top2; i++) 
    {
        cout << stack2[i];
    }
    cout << '\n';
}
int main() 
{
    char str[N];
    cout << "Enter String : ";
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        push(stack1, top1, str[i]);
    }
    reverse();
    return 0;
}
