#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e9);
        distance[S] = 0;

        for(int i = 0; i < V - 1; i++) {
            for(auto &it : edges) {
                int u = it[0], v = it[1], wt = it[2];

                if(distance[u] != 1e9 && distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        for(auto& it : edges) {
            int u = it[0], v = it[1], wt = it[2];

            if(distance[u] != 1e9 && distance[u] + wt < distance[v]) return {-1};
        }

        return distance;
	}
};
