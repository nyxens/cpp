#include <iostream>
#include <queue>
using namespace std;
#define V 8
#define E 8 
int a[V][E];
int deg[V] = {0};
bool vis[V] = {0}; 

void BFS(int start){
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0;i < deg[node];i++){
            int neighbor = a[node][i];
            if(!vis[neighbor]){
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main(){

    a[0][deg[0]++] = 1;
    a[0][deg[0]++] = 3;
    a[0][deg[0]++] = 2;
    a[1][deg[1]++] = 4;
    a[1][deg[1]++] = 7;
    a[2][deg[2]++] = 0;
    a[2][deg[2]++] = 5;
    a[3][deg[3]++] = 0;
    a[4][deg[4]++] = 1;
    a[4][deg[4]++] = 5;
    a[5][deg[5]++] = 6;
    a[5][deg[5]++] = 4;
    a[5][deg[5]++] = 2;
    a[6][deg[6]++] = 5;
    a[7][deg[7]++] = 1;

    cout << "BFS Traversal : ";
    BFS(0);
    cout << endl;
    return 0;
} 