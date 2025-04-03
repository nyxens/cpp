#include <iostream>
using namespace std;
#define V 8
#define E 8
int a[V][E]; 
int deg[V] = {0}; 
bool vis[V] = {0}; 

void DFS(int v){
    vis[v] = true;
    cout << v << " ";
    for(int i = 0; i < deg[v]; i++){
        int n = a[v][i];
        if(!vis[n]){
            DFS(n);
        }
    }
}
void findConnectedComponents(){
    int components = 0;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            components++;
            cout << "Connected Component " << components << " : ";
            DFS(i);
            cout << endl;
        }
    }
    cout << "Number of CC : " << components << endl;
}
int main(){

    a[0][deg[0]++] = 1;
    a[0][deg[0]++] = 3;
    a[0][deg[0]++] = 2;
    a[1][deg[1]++] = 7;
    a[2][deg[2]++] = 0;
    a[3][deg[3]++] = 0;
    a[4][deg[4]++] = 1;
    a[4][deg[4]++] = 5;
    a[5][deg[5]++] = 6;
    a[5][deg[5]++] = 4;
    a[5][deg[5]++] = 2;
    a[6][deg[6]++] = 5;
    a[7][deg[7]++] = 1;

    findConnectedComponents();
    return 0;
} 