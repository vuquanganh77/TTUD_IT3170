#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
vector<int> adj[1001];
int n,m;

void dfs(int u){
    //cout << u << " ";
    visited[u] = true;

    for(int i : adj[u]){
        if(!visited[i]) dfs(i);
    }
}

void connected_component(){
    int count = 0;
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            count ++;
            dfs(i);
        }
    }

    cout << count << endl;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connected_component();
    return 0;
}

