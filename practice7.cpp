#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[7];
bool visited_bfs[7] = {false};
bool visited_dfs[7] = {false};
int bfs_count = 0;
int dfs_count = 0;
void BFS(int s){
    queue<int> q;
    q.push(s);
    visited_bfs[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbor : adj[node]){
            if(!visited_bfs[neighbor]){
                visited_bfs[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
void DFS(int s){
    visited_dfs[s] = true;
    cout << s << " ";
    for(int neighbor : adj[s]){
        if(!visited_dfs[neighbor]){
            DFS(neighbor);
        }
    }
}
void BFSTraversal(int v){
    cout << "BFS Traversal: ";
    for(int i = 0; i < v; i++){
        if(!visited_bfs[i]){
            BFS(i);
            bfs_count++;
            cout << " (Connected Component " << bfs_count << ") ";
        }
    }
    cout << endl;
}
void DFSTraversal(int v){
    cout << "DFS Traversal: ";
    for (int i = 0; i < v; i++){
        if(!visited_dfs[i]){
            DFS(i);
            dfs_count++;
            cout << " (Connected Component " << dfs_count << ") ";
        }
    }
    cout << endl;
}
int main() {

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(4);
    BFSTraversal(7);
    DFSTraversal(7);    
    return 0;
}
