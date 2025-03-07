#include <iostream>
#include <cstring>//strlen()
#include <cstdlib>//exit()
#define N 100
using namespace std;

char stack[N];
char infix[N], postfix[N];
int top = -1;

void push(char c) 
{
    if (top == N - 1) 
    {
        cout << "Stack overflow\n";
        return;
    }
    stack[++top] = c;
}

char pop() 
{
    if (top == -1) 
    {
        cout << "Stack underflow!\n";
        exit(1);
    }
    return stack[top--];
}

bool isempty() 
{
    return top == -1;
}

void print() 
{
    int i = 0;
    while (postfix[i])
        cout << postfix[i++];
    cout << "\n";
}

int precedence(char symbol) 
{
    switch (symbol) 
    {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void intopost() 
{
    int i, j = 0;
    char symbol, next;
    int length = strlen(infix);
    for (i = 0; i < length; i++) 
    {
        symbol = infix[i];
        switch (symbol) 
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while (!isempty() && (next = pop()) != '(')
                    postfix[j++] = next;
                if (!isempty() && stack[top] == '(') 
                    pop();
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                while (!isempty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    while (!isempty()) 
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() 
{
    cout << "Enter the infix expression: ";
    cin.getline(infix, N);
    intopost();
    print();
    return 0;
}
