#include <bits/stdc++.h>

using namespace std;

class graph
{
    unordered_map<int, list<int>> adj;

public:
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
            adj[v].push_back(u);
    }

    void printEdge()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";

            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout <<endl;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;
    cout <<endl;

    graph g;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printEdge();

    return 0;
}