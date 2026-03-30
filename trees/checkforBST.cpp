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
    bool isBST(TreeNode *root)
    {
        // your code goes here
        vector<int> v;
        inOrder(root, v);
        int n = v.size();

        for(int i = 0; i < n - 1; i++) {
            if(v[i] >= v[i + 1]) return false;
        }

        return true;
    }
private:
    void inOrder(TreeNode * root, vector<int> &v) {
        if(root == nullptr) return;
        //l, n, r
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
};