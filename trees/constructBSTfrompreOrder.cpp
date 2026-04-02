#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        // your code goes here
        int index = 0;
        return constructBST(preorder, index, INT_MAX);
    }

private:
    TreeNode *constructBST(vector<int> &v, int &current, int bound)
    {
        if (current == v.size() || v[current] > bound)
            return nullptr;

        TreeNode *root = new TreeNode(v[current++]);

        root->left = constructBST(v, current, root->data);
        root->right = constructBST(v, current, bound);

        return root;
    }
};