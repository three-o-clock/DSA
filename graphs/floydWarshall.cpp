#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        // for my sake, no edge exists = 1e5

        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) matrix[i][j] = 1e5;
            }
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1e5) matrix[i][j] = -1;
            }
        }
	}
};

int main() {

    return 0;
}


class Solution {
   public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int kruskal(vector<vector<int>>& vec) {
        int sum = 0;
        for(auto& temp : vec) {
            int u = temp[0], v = temp[1], wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
        }

        return sum;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        // kruskal's
        // vector<vector<vector<int>>>

        parent.resize(V);
        rank.resize(V);

        for(int i = 0; i < V; i++) parent[i] = i;

        vector<vector<int>> vec;

        for (int u = 0; u < V; u++) {
            for (auto& it : adj[u]) {
                int v = it[0], wt = it[1];

                if(u < v) vec.push_back({u, v, wt});
            }
        }

        auto lambda = [](const auto& v1, const auto& v2) {
            return v1[2] < v2[2];  // sort by weight
        };

        sort(vec.begin(), vec.end(), lambda);

        return kruskal(vec);
    }
};
