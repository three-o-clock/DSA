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
	vector<int> kLargesSmall(TreeNode* root, int k){
		//your code goes here
        vector<int> nodesList;
        inOrder(root, nodesList);

        vector<int> ans;
        int size = nodesList.size();

        ans.push_back(nodesList[k - 1]);
        ans.push_back(nodesList[size - k]);

        return ans;
	}
private:
    void inOrder(TreeNode * root, vector<int> &v) {
        if(root == nullptr) return;

        inOrder(root->left, v);
        v.push_back(root->data);
        inOrder(root->right, v);
    }
};