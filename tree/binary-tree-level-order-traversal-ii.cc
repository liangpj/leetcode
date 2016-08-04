#include "../header.h"

/**Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

/*首先进行自顶向下进行层次遍历
*/
void _levelOrderBottom(TreeNode *root, int level,
                  vector<vector<int>> &res)
{
    if (!root)
        return ;
    if (res.empty() || level > (res.size()-1))
        res.push_back(vector<int>());
    res[level].push_back(root->val);
    _levelOrderBottom(root->left, level+1, res);
    _levelOrderBottom(root->right, level+1, res);
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> res;

    _levelOrderBottom(root, 0, res);
    std::reverse(res.begin(), res.end());
    return res;
}

int binTree_level_OrderII_main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto res = levelOrderBottom(root);
    for(auto e : res) {
        for(auto i : e)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
