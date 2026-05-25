#include<bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        int size = nums.size();

        for(int i = 0; i < size; i++) {
            index[nums[i]] = i;
        }

        int complement;

        for(int i = 0; i < size; i++) {
            complement = target - nums[i];

            if(index.count(complement) && index[complement] != i) {
                return {i, index[complement]};
            } 
        }

        return {};

    }
};
