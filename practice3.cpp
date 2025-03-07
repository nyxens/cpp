#include <iostream>//io
#include <stack>//stack
#include <string>//string
#include <cmath>//pow()
#include <cctype>//isdigit()and isalnum()
using namespace std;
bool isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; 
}
int precedence(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return 0;
}
string intopost(string infix){
    stack<char> s;
    string postfix = "";
    for(char c:infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if(c==')'){
            while(!s.empty()&&s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.empty()&&precedence(c)<=precedence(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int evaluatePostfix(string postfix) {
    stack<int> s;
    for(char c:postfix){
        if(isdigit(c)){
            s.push(c-'0');
        }
        else if(isOperator(c)){
            int b = s.top();
            s.pop();
            int a = s.top(); 
            s.pop();
            int result;
            if(c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;
            else if (c == '^') result = pow(a, b);
            s.push(result);
        }
    }
    return s.top();
}
int main(){
    string infix;
    cout << "Enter Infix : ";
    cin >> infix;
    string postfix = intopost(infix);
    cout << postfix <<'\n';
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << '\n';
    return 0;
}