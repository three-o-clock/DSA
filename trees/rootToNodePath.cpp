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
    vector<vector<int>> allRootToLeaf(TreeNode *root)
    {
        // your code goes here
        vector<int> path;
        vector<vector<int>> allPaths;
        rootToLeafPaths(root, path, allPaths);

        return allPaths;
    }

private:
    void rootToLeafPaths(TreeNode *root, vector<int> &v, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        v.push_back(root->data);

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(v);
        }

        if(root->left != NULL)
        {
            rootToLeafPaths(root->left, v, ans);
        }

        if(root->right != NULL)
        {
            rootToLeafPaths(root->right, v, ans);
        }

        v.pop_back();
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<vector<int>> paths = solution.allRootToLeaf(root);

    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
