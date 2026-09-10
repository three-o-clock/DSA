#include <bits/stdc++.h>
using namespace std;

// 0,0 ----> 0,2 -> 0 + 2 mod 2 = 0 |  
// 0,1 ----> 1,2 -> 

// 1, 2, 3, 4, 5, 6, 7, 8, 9 -> flat out the array 
// -> and then use rotate array with mod 3 
// --> 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            for(j = )
        }


        
    }
};

int main() {

    return 0;
}