#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<char> dq;
int main(){
    string input;
    cout << "Enter your String : ";
    cin >> input;
    for(int i=0;i<input.length();i++)
        dq.push_back(input[i]);
    while(dq.size()>1){
        if(dq.front()==dq.back()){
            dq.pop_front();
            dq.pop_back();
        }
        else{
            cout<<"not a palindrome!\n";
            return 0;
        }
    }
    cout << "its a palindrome!\n";
    return 0;
}