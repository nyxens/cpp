#include <iostream>
#include <queue>
using namespace std;
#define V 8 
#define E 8 
int a[V][E]; 
int deg[V] = {0};
int indeg[V] = {0};

void topologicalSort(){
    queue<int> q;
    for(int i = 0;i < V;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    cout << "Topological Sort : ";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0;i < deg[node];i++){
            int neighbor = a[node][i];
            indeg[neighbor]--;
            if(indeg[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
int main(){

    a[0][deg[0]++] = 1;
    a[0][deg[0]++] = 3;
    a[0][deg[0]++] = 2;
    a[1][deg[1]++] = 4;
    a[1][deg[1]++] = 7;
    a[2][deg[2]++] = 5;
    a[3][deg[3]++] = 6;
    a[4][deg[4]++] = 5;
    a[5][deg[5]++] = 6;

    for(int i = 0;i < V;i++){
        for(int j = 0;j < deg[i];j++){
            int neighbor = a[i][j];
            indeg[neighbor]++;
        }
    }
    topologicalSort();
    return 0;
} 