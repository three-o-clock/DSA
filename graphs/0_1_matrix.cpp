#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) { // n
            for(int j = 0; j < m; j++) { // m 
                if(mat[i][j] == 0)  {
                    q.push({i, j});
                    distance[i][j] = 0;
                }  
            }
        } // m*n 

        auto isSafe = [&](const int& x, const int& y) {
            return x >= 0 && x < n && y >= 0 && y < m; 
        };

        while(!q.empty()) { // m*n
            auto coordinates = q.front(); // coordinates of cell storing 1
            q.pop();

            int x = coordinates.first, y = coordinates.second;

            for(auto& dir : directions) { // runs 4 times for every node
                int x_ = x + dir[0], y_ = y + dir[1];

                if(isSafe(x_, y_) && distance[x_][y_] == INT_MAX) {
                    // safe and unvisited
                    distance[x_][y_] = distance[x][y] + 1;
                    q.push({x_, y_});
                }  
            }
        }

        return distance;
    }
};

int main() {

    return 0;
}