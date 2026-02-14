#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize the node with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> floorCeilOfBST(TreeNode *root, int key)
    {
        // your code goes here
        vector<int> v;
        pair<int, int> ans;
        int floor = -1, ceil = -1;
        ans = findFloorCeil(root, floor, ceil, key);

        v.push_back(ans.first);
        v.push_back(ans.second);

        return v;
    }

private:
    pair<int, int> findFloorCeil(TreeNode *root, int &floor, int &ceil, int key)
    {
        if (root == nullptr)
            return {floor, ceil};

        if (key == root->data)
        {
            floor = root->data;
            ceil = root->data;
            return {floor, ceil};
        }

        else if (key > root->data)
        {
            floor = root->data;
            return findFloorCeil(root->right, floor, ceil, key);
        }

        else if (key < root->data)
        {
            ceil = root->data;

            return findFloorCeil(root->left, floor, ceil, key);
        }

        return {floor, ceil};
    }
};