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

class Solution
{
public:
    vector<int> bottomView(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;

        if (!root)
            return ans;

        map<int, map<int, int>> nodes; // x, y, node->data
        // using multiset because there can be nodes with the same value but at the same x,y
        queue<pair<TreeNode *, pair<int, int>>> q; // TreeNode*, x ,y

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *currentNode = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y] = currentNode->data;

            if (currentNode->left)
            {
                q.push({currentNode->left, {x - 1, y + 1}});
            }

            if (currentNode->right)
            {
                q.push({currentNode->right, {x + 1, y + 1}});
            }
        }

        for (auto i : nodes)
        {
            auto &j = i.second;
            {
                auto it = prev(j.end());
                ans.push_back(it->second);
            }

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

    // Get the Bottom View traversal
    vector<int> bottomView = solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottomView)
    {
        cout << node << " ";
    }

    return 0;
}

/*
store x and y and node->data in a map. map<int, map<int,multiset<int>>> || x y and node->data
if there are multiple nodes at the same x, consider the one with the largest y.
    since map is already sorted, we don't need to worry about the left to right order
     do i need to store all nodes at the same x and then extract the one with the largest y
  or is there some way i can do it directly?

    let's try method 1.
     first, elements in the map will be stored in ascending order according to x
     so first element in map = smallest x = leftmost node
     now, i need the element at the END (for largest y)
  */