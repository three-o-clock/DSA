#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


// important
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        // multiset because nodes in the same vertical can have the same value. hence did not use set
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {x, y}}

        // visualize cartesian plane and root as origin
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            // cartersian plane
            int x = p.second.first;
            int y = p.second.second;
            TreeNode * currentNode = p.first;

            nodes[x][y].insert(currentNode->data);

            if(currentNode->left) {
                q.push({currentNode->left, {x - 1, y + 1}});
            }

            if(currentNode->right) {
                q.push({currentNode->right, {x + 1, y + 1}});
            }
        }

        for(auto i : nodes) {
            vector<int> VerticalColumn;

            for(auto j : i.second) {
                // insert all nodes on the same vertical [x] at the end of the vector verticalColumn 
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
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(7);

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