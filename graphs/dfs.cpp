#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int u, vector<bool> &visited, vector<int>& result) {
    if(visited[u]) return;

    visited[u] = true;
    result.push_back(u);

    for(int& v : adj[u]) {
        if(!visited[v]) dfs(adj, v, visited, result);
    }
}

int main() {

}