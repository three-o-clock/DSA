#include<bits/stdc++.h>
using namespace std;

struct TreeTreeNode {
    int data;
    TreeTreeNode* left;
    TreeTreeNode* right;
    TreeTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


// important
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeTreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        // multiset because TreeNodes in the same vertical can have the same value. hence did not use set
        map<int, map<int, multiset<int>>> TreeNodes;
        queue<pair<TreeTreeNode*, pair<int, int>>> q; // {TreeNode, {x, y}}

        // visualize cartesian plane and root as origin
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            // cartersian plane
            int x = p.second.first;
            int y = p.second.second;
            TreeTreeNode * currentTreeNode = p.first;

            TreeNodes[x][y].insert(currentTreeNode->data);

            if(currentTreeNode->left) {
                q.push({currentTreeNode->left, {x - 1, y + 1}});
            }

            if(currentTreeNode->right) {
                q.push({currentTreeNode->right, {x + 1, y + 1}});
            }
        }

        for(auto i : TreeNodes) {
            vector<int> VerticalColumn;

            for(auto j : i.second) {
                // insert all TreeNodes on the same vertical [x] at the end of the vector verticalColumn 
                VerticalColumn.insert(VerticalColumn.end(), j.second.begin(), j.second.end()); 
            }

            ans.push_back(VerticalColumn);
        }

        return ans;
    }
        
};


// // Main method to test the verticalTraversal function
// int main() {
//     // Creating a binary tree
//     TreeTreeNode* root = new TreeTreeNode(1);
//     root->left = new TreeTreeNode(2);
//     root->right = new TreeTreeNode(3);
//     root->left->left = new TreeTreeNode(4);
//     root->left->right = new TreeTreeNode(5);
//     root->right->left = new TreeTreeNode(6);
//     root->right->right = new TreeTreeNode(7);

//     // Creating an instance of Solution
//     Solution sol;

//     // Getting the vertical order traversal
//     vector<vector<int>> result = sol.verticalTraversal(root);

//     // Printing the result
//     cout << "Vertical Order Traversal: " << endl;
//     for (const auto& col : result) {
//         for (int num : col) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }