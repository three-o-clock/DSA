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
    long long int widthOfBinaryTree(TreeNode *root)
    {
        // your code goes here
        queue<TreeNode *> q;
        vector<TreeNode *> v;

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            v.push_back(current);
            q.pop();

            if (current == nullptr)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }

            else
            {
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
        }
    }
};