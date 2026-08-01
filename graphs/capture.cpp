#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
       // n*m 
       // X or O 
       // replace all Os that are surrounded with Xs with Xs 

       // start from the boundary and apply dfs on all boundary Os 
       // convert the connected nodes to Z 
       // now replace all the remaining Os with Xs because now it is guaranteed that they are cut off from the outside 
       // convert all the Zs back to Os 

       int row = mat.size(), column = mat[0].size();

        if(row == 1 && column == 1) return mat;

        for(int i = 0; i < row; i++) { // m 
            for(int j = 0; j < column; j++) {  // n 
                if(i == 0 || i == row - 1 || j == 0 || j == column - 1) {
                    // this is a boundary node 
                    dfs(mat, row, column, i, j); 
                }
            }
        }  // m * n 

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(mat[i][j] == 'Z') mat[i][j] = 'O';
            }
        }

        return mat;       
    }

private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<char>>& mat, int row, int column, int i, int j) { // m * n 
        if(mat[i][j] != 'O') return; 

        mat[i][j] = 'Z';

        for(auto& dir : directions) {
            int i_ = i + dir[0], j_ = j + dir[1];

            if(isSafe(row, column, i_, j_)) dfs(mat, row, column, i_, j_);
        }
    }

    bool isSafe(int row, int column, int x, int y) {
        return x >= 0 && x < row && y >= 0 && y < column;
    }
};

int main() {

    return 0;
}