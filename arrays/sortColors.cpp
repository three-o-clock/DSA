#include <bits/stdc++.h>
using namespace std;

// red, white, blue 
// 0, 1, 2
// don't use nums.sort()
// sort in-place 

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int red = 0, white = 0, blue = 0;

//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             if(nums[i] == 0) red++;
//             else if(nums[i] == 1) white++;
//             else blue++;
//         }

//         int i = 0;

//         while(red != 0) {
//             nums[i] = 0;
//             red--;
//             i++;
//         }

//         while(white != 0) {
//             nums[i] = 1;
//             white--;
//             i++;
//         }

//         while(blue != 0) {
//             nums[i] = 2;
//             blue--;
//             i++;
//         }
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int red = 0, white = 0, blue = n - 1;

        while(white <= blue) {
            if(nums[white] == 2) {
                swap(nums[white], nums[blue]);
                blue--;
            }
            else if(nums[white] == 0) {
                swap(nums[white], nums[red]);
                red++;
                white++;
            }

            else white++;
        }
        
    }
};

int main() {

    Solution s;

    vector<int> nums = {2, 1, 2};
    // vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);

    int n = nums.size();

    for(int i = 0; i < n; i++) {
        cout <<nums[i] <<" ";
    }

    return 0;
}