#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], int u, vector<bool>& visited) {
    queue<pair<int,int>> q;
    q.push({u, -1});
    visited[u] = true;

    while(!q.empty()) {
        auto i = q.front();
        q.pop();

        for(int& v : adj[i.first]) {
            if(i.second == v) continue;
            else if(visited[v]) return true;
            else {
                q.push({v, i.first});
                visited[v] = true;
            }
        }
    }

    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    if(V == 1) return false;

    vector<bool> visited(V, false);
    
    for(int u = 0; u < V; u++) {
        if(!visited[u] && bfs(adj, u, visited)) return true;
    }

    return false;
}

