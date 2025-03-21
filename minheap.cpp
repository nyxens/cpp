#include <iostream>
using namespace std;
int heap[30];
int heapSize = 0;
void heapifyUp(int i){
    while(i>0 && heap[(i-1)/2]>heap[i]){
        swap(heap[(i-1)/2],heap[i]);
        i = (i-1)/2;
    }
}
void heapifyDown(int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<heapSize && heap[left]<heap[smallest]){
        smallest = left;
    }
    if(right<heapSize && heap[right]<heap[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[i],heap[smallest]);
        heapifyDown(smallest);
    }
}
void insert(int value){
    if (heapSize == 30){
        cout << "Full Heap!";
        return;
    }
    heap[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}
int getMin(){
    if(heapSize == 0){
        cout << "Heap is empty";
        return -1;
    }
    return heap[0];
}
void deleteMin(){
    if(heapSize == 0){
        cout << "Heap is empty";
        return;
    }
    heap[0] = heap[heapSize-1];
    heapSize--;
    heapifyDown(0);
}
void print(){
    for(int i=0;i<heapSize;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main(){
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);
    insert(50);
    insert(65);
    insert(70);
    cout << "Min Heap: ";
    print();
    cout << "Min Element: ";
    if (getMin() == -1)
        cout << "No min element!" << endl;
    else
        cout << getMin() << endl;
    deleteMin();
    cout << "Min Heap: ";
    print();
    return 0;
}