#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001];
vector<int> adj[1001];

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        memset(visited, false, sizeof(visited));
    }
}

void bfs(int u){
    // buoc khoi tao
    queue<int> q;
    q.push(u);
    visited[u] = true;

    // buoc duyet
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int i: adj[v]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    input();
    bfs(1);
    return 0;
}