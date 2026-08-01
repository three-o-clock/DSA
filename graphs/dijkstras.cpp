#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        // 0 -> {{1, 2}, {3, 1}} || {{neighbour, weight}}
        // {{0, 1, 2}}
        vector<vector<pair<int, int>>> adj(V);

        for(auto& e : edges) { // E
            int u = e[0], v = e[1], weight = e[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {weight, destination}
        vector<int> shortestDistance(V, 1e9);
        shortestDistance[S] = 0;
        pq.push({0, S});

        while(!pq.empty()) { // V
            int wt = pq.top().first, node = pq.top().second;
            pq.pop(); // log(V)

            if(wt > shortestDistance[node]) continue;

            for(auto& i : adj[node]) { // E 
                int v = i.first, w = i.second;

                if(wt + w < shortestDistance[v]) {
                    shortestDistance[v] = wt + w;
                    pq.push({wt + w, v}); // log(V)
                }
            }
        }

        return shortestDistance;
    }
};

// E + V(logV + Elogv) 

int main() {

    return 0;
}

// vector<vector<int>> adj;
// for(int& v : adj[u])

// unit weights -> bfs 