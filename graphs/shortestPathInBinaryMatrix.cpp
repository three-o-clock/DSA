#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
            pq;
        // {distance, {x, y}}
        pq.push({0, {0, 0}});
        grid[0][0] = 1; // visited
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int distance = p.first;
            auto coordinates = p.second;
            int x = coordinates.first, y = coordinates.second;

            for (auto &dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && grid[x_][y_] == 0 &&
                    (distance + 1 < result[x_][y_]))
                {
                    pq.push({distance + 1, {x_, y_}});
                    grid[x_][y_] = 1;
                    result[x_][y_] = distance + 1;
                }
            }
        }

        return result[n - 1][n - 1] == INT_MAX ? -1 : result[n - 1][n - 1] + 1;
    }
};