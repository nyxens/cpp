#include <iostream>
#include <cmath>   //pow()
#include <cctype>  //isdigit()
#include <cstdlib> //exit()
#define N 20       
using namespace std;
int stack[N];
int top = -1;
void push(int value) 
{
    if (top == N - 1) 
    {
        cout << "Stack overflow!\n";
        exit(1);
    }
    stack[++top] = value;
}
int pop() 
{
    if (top == -1) 
    {
        cout << "Stack underflow!\n";
        exit(1);
    }
    return stack[top--];
}
int evaluatePostfix(char* postfix) 
{
    for (int i = 0; postfix[i] != '\0'; i++) 
    {
        char symbol = postfix[i];
        if (isdigit(symbol)) 
            push(symbol - '0');
        else 
        {
            if (top < 1) //cannot pop 2 elemnts if top < 1 so error in input
            {
                cout << "Invalid postfix expression.\n";
                exit(1);
            }
            int operand2 = pop();
            int operand1 = pop();
            switch (symbol) 
            {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) 
                    {
                        cout << "Division by zero error.\n";
                        exit(1);
                    }
                    push(operand1 / operand2);
                    break;
                case '^':
                    push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Unsupported operator: " << symbol << '\n';
                    exit(1);
            }
        }
    }
    if (top == 0) //after loop 1 element is stored that is the result.
        return pop();
    else 
    {
        cout << "Invalid postfix expression.\n";
        exit(1);
    }
}
int main() 
{
    char postfix[N];
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Result of the expression: " << result << '\n';
    return 0;
}
