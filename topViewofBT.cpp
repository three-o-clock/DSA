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

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        //your code goes here 
        vector<int> ans;

        if(!root) return ans;

        map<int, int> TreeNodes; // x -> TreeNode->data
        queue<pair<TreeNode *, int>> q; // TreeNode, x

        q.push({root, 0});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode * currentTreeNode = p.first;
            int x = p.second;

            if(TreeNodes.find(x) == TreeNodes.end()) {
                // encountering this x axis for the first time
                TreeNodes[x] = currentTreeNode->data;
            }

            if(currentTreeNode->left) {
                q.push({currentTreeNode->left, x - 1});
            }

            if(currentTreeNode->right) {
                q.push({currentTreeNode->right, x + 1});
            }
        }

        for(auto i : TreeNodes) {
            ans.push_back(i.second);
        }

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

    // Get the top view traversal
    vector<int> topView = solution.topView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView)
    {
        cout << node << " ";
    }

    return 0;
}
