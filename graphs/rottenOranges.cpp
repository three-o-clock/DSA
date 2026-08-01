#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int n = grid.size(), m = grid[0].size();

    int freshOranges = 0;

    for (int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) freshOranges++;
        }
    }

    if(freshOranges == 0) return 0;

    auto isSafe = [&](int& x, int&y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    int minutes = 0;

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            auto p = q.front();
            q.pop();

            int i = p.first, j = p.second;

            for(auto& dir : directions) {
                int i_ = i + dir[0], j_ = j + dir[1];

                if(isSafe(i_, j_) && grid[i_][j_] == 1) {
                    grid[i_][j_] = 2;
                    freshOranges--;
                    q.push({i_, j_});
                }
            }
        }
        minutes++;
    }

    return freshOranges > 0 ? -1 : minutes - 1;
}

int main() {

    return 0;
}