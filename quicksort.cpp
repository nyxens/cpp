#include <iostream>
#include <vector>
using namespace std;
int part(vector<int> &a,int s, int e){
    int i = s-1;
    int pvt = a[e];
    for(int j = s;j<e;j++){
        if(a[j]<=pvt){
            i++;
            swap(a[j],a[i]);
        }
    }
    i++;
    swap(a[e],a[i]);
    return i;
}
void quicksort(vector<int> &a,int s, int e){
    if(s<e){
        int pvt = part(a,s,e);
        quicksort(a,s,pvt-1);
        quicksort(a,pvt+1,e);
    }
}
int main(){
    vector<int> a = {2,6,3,4,7,1,8,9,5};
    quicksort(a,0,a.size()-1);
    for(int val:a){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}