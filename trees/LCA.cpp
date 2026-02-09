#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // your code goes here
        if (root == p || root == q || root == nullptr)
        {
            return root;
        }

        TreeNode *temp1 = lowestCommonAncestor(root->left, p, q);

        TreeNode *temp2 = lowestCommonAncestor(root->right, p, q);

        if (temp1 != nullptr && temp2 != nullptr)
        {
            return root;
        }

        if (temp1 == nullptr)
        {
            return temp2;
        }

        if (temp2 == nullptr)
        {
            return temp1;
        }
    }
};

int main()
{
    // Construct a simple binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution solution;
    TreeNode *p = root->left;  // Node with value 5
    TreeNode *q = root->right; // Node with value 1

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}
