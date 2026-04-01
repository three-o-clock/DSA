#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution{	
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        //your code goes here
            if(root == nullptr) return root;
            if(p < root->data && q < root->data) return lca(root->left, p, q);
            if(p > root->data && q > root->data) return lca(root->right, p, q);
            
            return root;

		}
};