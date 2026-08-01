#include <bits/stdc++.h>

using namespace std;

class graph {
    vector<vector<int>> adj;

public:
    vector<vector<int>> createGraph(int V, vector<vector<int>> &edges, bool direction) {
        vector<vector<int>> mat(V, vector<int>(V, 0));

        for(auto &i : edges) {
            int u = i[0];
            int v = i[1];

            mat[u][v] = 1;

            if(direction == 0) mat[v][u] = 1;
        }

        return mat;
    }
};

int main()
{
    graph g;
    int V = 5;
    vector<vector<int>> edges = {{0, 1},{0, 3},{1, 2}, {1, 0}, {2,1}, {2,3}, {2,4}, {3,0}, {3,2}, {3,4}, {4,3}, {4,2}};

    vector<vector<int>> mat = g.createGraph(V, edges, 0);

    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}

int V;
vector<int> parent(V);
for(int i = 0; i <V; i++) parent[i] = i;
vector<int> rank(V, 0);


int find(int x) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
} 

void UnionSet(int x, int y) {
    int parent_x = find(x);
    int parent_y = find(y);

    if(parent_x == parent_y) return;

    if(rank[parent_x] < rank[parent_y]) {
        parent[parent_x] = parent_y;
    }

    else if(rank[parent_x] > rank[parent_y]) {
        parent[parent_y] = parent_x;
    }

    else {
        parent[parent_x] = parent_y;
        rank[parent_y]++;
    }
}