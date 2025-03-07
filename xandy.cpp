#include <iostream>
using namespace std;
int convert(int x,int y){
    while(x != y){
        if(x>y){
            x--;
        }
        else{
            x*=2;
        }
    }
    return x;
}
int main()
{
    int x, y;
    cout << "Enter the elements" << '\n';
    cin >> x >> y;
    cout << "Converted values : ";
    cout << convert(x,y) << " ";
    cout << convert(y,x) << "\n";
}