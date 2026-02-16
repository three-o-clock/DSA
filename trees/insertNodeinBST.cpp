
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // your code goes here
        if (root == nullptr)
            return nullptr;

        if (val > root->data)
        {
            if (root->right == nullptr)
            {
                TreeNode *newNode = new TreeNode(val);
                root->right = newNode;
            }
            else
                insertIntoBST(root->right, val);
        }

        if (val < root->data)
        {
            if (root->left == nullptr)
            {
                TreeNode *newNode = new TreeNode(val);
                root->left = newNode;
            }
            else
                insertIntoBST(root->left, val);
        }

        return root;
    }
};