#include <iostream>
#include <stack>
using namespace std;
const int n = 5;
int b[n];
void NextLargest(int a[]){
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            b[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        b[s.top()]=-1;
        s.pop();
    }
}
int main(){
    int a[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    NextLargest(a);
    for (int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    return 0;
}