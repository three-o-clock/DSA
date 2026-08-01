#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v, bool directed)
    {
        adj[u].push_back(v);
        if (directed == false)
            adj[v].push_back(u);
    }

    void printEdge()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";

            for (int &v : i.second)
                cout << v << ", ";

            cout << endl;
        }
    }

    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
    {
        if (visited[u])
            return;

        visited[u] = true;
        result.push_back(u);

        for (int &v : adj[u])
        {
            if (!visited[v])
                dfs(adj, v, visited, result);
        }
    }

    void bfs(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        result.push_back(u);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int &v : adj[u])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }

    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, int parent) {
        visited[u] = true;

        for(int& v : adj[u]) {
            if(parent == v) continue;
            else if(visited[v]) return true;
            else {
                if(isCycleDFS(adj, v, visited, u)) return true;
            }
        }

        return false;
    }

    
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 3, 0);

    g.printEdge();

    return 0;
}