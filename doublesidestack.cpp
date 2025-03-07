#include <iostream>
using namespace std;
#define N 10
struct DoubleStack{
    int arr[N];
    int top1;
    int top2;
};
void initialize(DoubleStack &ds){
    ds.top1 = -1;
    ds.top2 = N;
}
bool push1(DoubleStack &ds,int value){
    if(ds.top1 + 1 < ds.top2){ 
        ds.arr[++ds.top1] = value;
        return true;
    }else{
        cout << "Stack Overflow in Stack 1" << '\n';
        return false;
    }
}
bool push2(DoubleStack &ds,int value){
    if(ds.top2 - 1 > ds.top1){ 
        ds.arr[--ds.top2] = value;
        return true;
    }else{
        cout << "Stack Overflow in Stack 2" << '\n';
        return false;
    }
}
int pop1(DoubleStack &ds){
    if(ds.top1 >= 0){
        return ds.arr[ds.top1--];
    }else{
        cout << "Stack Underflow in Stack 1" << '\n';
        return -1; 
    }
}
int pop2(DoubleStack &ds){
    if(ds.top2 < N){
        return ds.arr[ds.top2++];
    }else{
        cout << "Stack Underflow in Stack 2" << '\n';
        return -1;
    }
}
void display(DoubleStack &ds){
    cout << "Stack 1: ";
    for (int i = 0; i <= ds.top1; i++){
        cout << ds.arr[i] << " ";
    }
    cout << "\nStack 2: ";
    for (int i = N - 1; i >= ds.top2; i--){
        cout << ds.arr[i] << " ";
    }
    cout << '\n';
}
int main(){
    DoubleStack ds;
    initialize(ds);
    push1(ds,10);
    push1(ds,20);
    push2(ds,90);
    push2(ds,80);
    display(ds);
    cout << "Popped from Stack 1: " << pop1(ds) << '\n';
    cout << "Popped from Stack 2: " << pop2(ds) << '\n';
    display(ds);
    return 0;
}
