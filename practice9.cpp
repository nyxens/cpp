#include <iostream>
using namespace std;
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    printarray(a,n);
}
void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int SI = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[SI])
                SI =j;
        }
        swap(a[i],a[SI]);
    }
    printarray(a,n);
}
void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
        int current = a[i];
        int prev = i-1;
        while( prev>=0 && a[prev]>current){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=current;
    }
    printarray(a,n);
}
int main(){
    int a[] = {5,3,7,2,9,1,4,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    bubblesort(a,n);
    selectionsort(a,n);
    insertionsort(a,n);
    return 0;   
}