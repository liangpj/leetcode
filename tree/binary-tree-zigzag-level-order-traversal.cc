#include "../header.h"

/**Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};




void _ziglevelOrder(TreeNode *root, int level, vector<vector<int>> &vec)
{
    if (!root)
        return;
    if (vec.empty() || level > (vec.size()-1))
        vec.push_back(vector<int>());
    vec[level].push_back(root->val);
    _ziglevelOrder(root->left, level+1, vec);
    _ziglevelOrder(root->right, level+1, vec);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    _ziglevelOrder(root, 0, res);

    for(int i = 1; i < res.size(); i += 2)
        reverse(res[i].begin(), res[i].end());
    return res;
}



int zigzagTree_main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto res = zigzagLevelOrder(root);
    for(auto e : res) {
        for(auto i : e)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
