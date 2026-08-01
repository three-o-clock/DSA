#include<bits/stdc++.h>
using namespace std;



bool isCycle(int V, vector<int> adj[]) {
    if(V == 1) return false;

    vector<int> indegree(V, 0);
    queue<int> q;
    int count = 0;

    // populate indegree vector
    for(int i = 0; i < V; i++) {
        for(int& j : adj[i]) {
            indegree[j]++;
        }
    }
    
    // push all the vertices with indegree == 0
    for(int u = 0; u < V; u++) {
        if(indegree[u] == 0) {
            q.push(u);
            count++;
        }
    }

    // main BFS loop
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int& v : adj[u]) {
            indegree[v]--;

            if(indegree[v] == 0) {
                q.push(v);
                count++;
            }
        }
    }

    if(count == V) return false;  // topological sort 
    else return true;
}

