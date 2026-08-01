#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        // if node's colour == newColor => visited
        // if node's colour == oldColour => unvisited

        // 1. if the starting node's colour == newColor -> it has already been visited and return 
        // 2. starting coordinates may not be (0, 0)
        // directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}

        if(image[sr][sc] == newColor) return image;

        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int oldColour = image[sr][sc];

        image[sr][sc] = newColor;

        auto isSafe = [&](int& x, int& y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int x = p.first, y = p.second;

            for(auto& dir : directions) {
                int x_ = x + dir[0], y_ = y + dir[1];

                if(isSafe(x_, y_) && image[x_][y_] == oldColour) {
                    q.push({x_, y_});
                    image[x_][y_] = newColor;
                }

            }
        }
        return image;
    }
};

int main() {

    return 0;
}