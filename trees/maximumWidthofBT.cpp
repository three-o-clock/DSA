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

        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;

        int ans = 0;

        q.push({root, 0});

        while (!q.empty())
        {
            int n = q.size();
            int leftMostIdx = q.front().second;

            int first, last;

            for (int i = 0; i < n; i++)
            {
                TreeNode *current = q.front().first;
                int currIdx = q.front().second - leftMostIdx; // index of nodes in a level relative to the leftmost node

                q.pop();

                if (i == 0)
                    first = currIdx;
                if (i == n - 1)
                    last = currIdx;

                if (current->left)
                    q.push({current->left, (2 * currIdx) + 1});
                if (current->right)
                    q.push({current->right, (2 * currIdx) + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};