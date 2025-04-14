#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> adj[7];
int count = 0;
void topo(){
    vector<int> indegree (7, 0);
    for(int i=0;i<7;i++){
        for(int neighbor:adj[i]){
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for(int i=0;i<7;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        count++;
        for(int neighbor:adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    if(count != 7){
        cout << "Topological Sort is not possible" << endl;
        return;
    }
}
int main(){
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(4);
    topo();
    cout << endl;
    return 0;
}