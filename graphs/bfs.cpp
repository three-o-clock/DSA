#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int u, vector<bool> &visited, vector<int>& result) {
    queue<int> q;

    q.push(u);
    visited[u] = true;
    result.push_back(u);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int &v : adj[u]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
                result.push_back(v);
            }
        }
    }
}


