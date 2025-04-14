#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a,int s,int mid, int e){
    vector<int> temp;
    int i = s;
    int j = mid+1;
    while( i <= mid && j <= e ){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(a[j]);
        j++;
    }
    for(int index = 0; index<temp.size();index++)
        a[index+s]=temp[index]; 
}
void mergesort(vector<int> &a,int s,int e){
    if(s<e){
        int mid = s + (e-s)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}
int main(){
    vector<int> a = {2,6,3,4,7,1,8,9,5};
    mergesort(a,0,a.size()-1);
    for(int val:a){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}