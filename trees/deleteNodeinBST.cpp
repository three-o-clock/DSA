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

class Solution {
   public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        // your code goes here

        // base case
        if (root == nullptr) return root;

        if (root->data > key) {
            root->left = deleteNode(root->left, key);
        }

        else if (root->data < key) {
            root->right = deleteNode(root->right, key);
        }

        else {
            // 0 child = leaf node
            if (root->right == nullptr && root->left == nullptr) {
                delete root;
                return nullptr;
            }

            // 1 child

            if (root->left != nullptr && root->right == nullptr) {
                // simply delete and replace
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            if (root->left == nullptr && root->right != nullptr) {
                // simply delete and replace
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // 2 children
            if (root->left != nullptr &&
                root->right != nullptr) {  // RST = right subtree
                int leastValinRST = (minValue(root->right))->data;
                root->data = leastValinRST;
                root->right = deleteNode(root->right, leastValinRST);
                return root;
            }
        }
        return root;
    }

   private:
    TreeNode *minValue(TreeNode *root) {
        // base case
        if (root->left == nullptr) {
            return root;
        }

        return minValue(root->left);
    }
};

int main()
{
    // Create a sample binary search tree.
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution sol;
    // Delete node with key 3 from the tree.
    root = sol.deleteNode(root, 3);

    return 0;
}