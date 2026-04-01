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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution
{
public:
    vector<int> succPredBST(TreeNode *root, int key)
    {
        vector<int> v;
        vector<int> ans;
        inOrder(root, v);

        int n = v.size(), i = 0;

        while (v[i] != key)
        {
            i++;
        }

        if (i != 0 && i != (n - 1))
        {
            ans.push_back(v[i - 1]);
            ans.push_back(v[i + 1]);
        }
        else if (i == 0)
        {
            ans.push_back(-1);
            ans.push_back(v[i + 1]);
        }
        else if (i == (n - 1))
        {
            ans.push_back(v[i - 1]);
            ans.push_back(-1);
        }

        return ans;
    }

private:
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        // l, n, r
        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
};

