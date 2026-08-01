#include <bits/stdc++.h>
using namespace std;

class Solution {
typedef pair<int, int> P;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n == 1) return 0;

        vector<vector<P>> adj(n);

        for(int i = 0; i < n - 1; i++) {
            int x = points[i][0], y = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x_ = points[j][0], y_ = points[j][1];

                int distance = abs(x - x_) + abs(y - y_);

                adj[i].push_back({distance, j});
                adj[j].push_back({distance, i});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(n, false);

        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int distance = p.first, u = p.second;

            if(inMST[u] == true) continue;

            inMST[u] = true;
            sum += distance;

            for(auto& it : adj[u]) {
                int wt = it.first, v = it.second;

                if(!inMST[v]) {
                    pq.push({wt, v});
                }
            }
        }

        return sum;
    }
}; 

int main() {

    return 0;
}