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
    vector<int> rightSideView(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        int n;

        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<TreeNode *> prevNodes;

        while (!q.empty())
        {
            TreeNode *current = q.front();
            prevNodes.push_back(current);
            q.pop();

            if (current == NULL)
            {
                if (!q.empty())
                {
                    n = prevNodes.size() - 2;
                    ans.push_back((prevNodes[n])->data);
                    q.push(NULL);
                }
            }

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        n = prevNodes.size() - 2;
        ans.push_back((prevNodes[n])->data);

        return ans;
    }
};

int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightSideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView)
    {
        cout << node << " ";
    }
    cout << endl;

    // // Get the Left View traversal
    // vector<int> leftView = solution.leftSideView(root);

    // // Print the result for Left View
    // cout << "Left View Traversal: ";
    // for (auto node : leftView) {
    //     cout << node << " ";
    // }
    // cout << endl;

    return 0;
}
