#include <iostream>
#include <deque>
using namespace std;
void window(int nums[],int n,int k){
    deque<int> dq;
    for(int i=0;i<n;++i){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            cout << nums[dq.front()] << " ";
        }
    }
}
int main() {
    int nums[] = {11,2,75,92,59,90,55};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 3;
    window(nums, n, k);
    return 0;
} 