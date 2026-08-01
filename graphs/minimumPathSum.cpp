#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // djikstra's

        int n = heights.size(), m = heights[0].size();
        // n x m
        if (n == 1 && m == 1)
            return 0;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int distance = p.first;
            auto coordinates = p.second;
            int x = coordinates.first, y = coordinates.second;

            if (distance > result[x][y]) continue;

            for (auto& dir : directions) {
                int x_ = x + dir[0], y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int edgeEffort = abs(heights[x_][y_] - heights[x][y]);
                    int newEffort = max(edgeEffort, result[x][y]);

                    if (newEffort < result[x_][y_]) {
                        pq.push({newEffort, {x_, y_}});
                        result[x_][y_] = newEffort;
                    }
                }
            }
        }

        return result[n - 1][m - 1];
    }
};