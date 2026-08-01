#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(vector<int> adj[], int u, vector<int> visited, stack<int> st) {
    visited[u] = true;

    for(int& v : adj[u]) {
        if(!visited[v]) dfs(adj, v, visited, st);
    }

    st.push(u);
}

vector<int> topologicalSort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) topologicalSortDFS(adj, i, visited, st);
    }

    vector<int> topopsortResult;

    while(!st.empty()) {
        int node = st.top();
        topopsortResult.push_back(node);
        st.pop();
    }

    return topopsortResult;
}

int main() {
    
    return 0;
}