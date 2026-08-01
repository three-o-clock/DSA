#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int u, vector<bool>& visited, int parent) {
    visited[u] = true;

    for(int &v : adj[u]) {
        if(v == parent) continue;
        else if(visited[v]) return true;
        else {
            if(dfs(adj, v, visited, u)) return true;
        }
    }

    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    if(V == 1) return false;

    vector<bool> visited(V, false);
    
    for(int u = 0; u < V; u++) {
        if(!visited[u] && dfs(adj, u, visited, -1)) return true;
    }

    return false;
}

