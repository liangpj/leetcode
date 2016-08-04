#include "../header.h"

/** Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

/**使用两个队列进行层次遍历
*/
vector<vector<int> > levelOrder_twoQue(TreeNode *root)
{
    queue<TreeNode *> first;
    queue<TreeNode *> second;
    vector<vector<int>> res;
    vector<int> curr;

    if (!root) return res;
    first.push(root);
    while(!first.empty() || !second.empty())
    {
        if (!first.empty()){
            curr.clear();
            while(!first.empty()){
                auto node = first.front();
                first.pop();
                curr.push_back(node->val);
                if (node->left) second.push(node->left);
                if (node->right) second.push(node->right);
            }
            res.push_back(curr);
        }else {
            curr.clear();
            while(!second.empty()) {
                auto node = second.front();
                second.pop();
                curr.push_back(node->val);
                if (node->left) first.push(node->left);
                if (node->right) first.push(node->right);
            }
            res.push_back(curr);
        }
    }
    return res;
}


/**使用空指针进行标记
*/
vector<vector<int>> levelOrder_Que(TreeNode *root)
{
    queue<TreeNode*> que;
    vector<vector<int>> res;
    vector<int> curr;

    if (!root)
        return res;
    que.push(root);
    que.push(nullptr);
    while(!que.empty()) {
        auto node = que.front();
        que.pop();
        if (node == nullptr) {
            res.push_back(curr);
            curr.clear();
            if (que.size() > 0)
                que.push(nullptr);
            }else {
                curr.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
    }
    return res;
}

/**
使用递归进行求解
*/
void _levelOrder(TreeNode *root, vector<vector<int>> &res, int level) {
    if(!root)
        return;
    if(res.empty() || level > (res.size() - 1))
        res.push_back(vector<int>());

    res[level].push_back(root->val);
    _levelOrder(root->left, res, level + 1);
    _levelOrder(root->right, res, level + 1);
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;

    _levelOrder(root, res, 0);
    return res;
}


int binTree_level_Order_main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto res = levelOrder(root);
    for(auto e : res) {
        for(auto i : e)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
