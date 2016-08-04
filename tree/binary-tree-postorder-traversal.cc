#include "../header.h"

/**
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

void fun(TreeNode *root, vector<int> &res)
{
    if (root) {
        fun(root->left, res);
        fun(root->right, res);
        res.push_back(root->val);
    }
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    fun(root, res);

    return res;
}

vector<int> postorderTraversal_noRecur(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> nodeSt;
    TreeNode *node = root;
    while (node || !nodeSt.empty()) {
        while(node) {
            res.push_back(node->val);
            nodeSt.push(node);
            node = node->right;
        }
        if (!nodeSt.empty()) {
            node = nodeSt.top();
            nodeSt.pop();
            node = node->left;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void preOrderTraver(TreeNode *root)
{
    stack<TreeNode*> nodeStack;
    TreeNode * node = root;
    while (node || !nodeStack.empty()) {
        while(node) {
            cout << node->val << " ";
            nodeStack.push(node);
            node = node->left;
        }
        if (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();
            node = node->right;
        }
    }

    cout << endl;
}

int binPostTravel()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    auto res = postorderTraversal(root);

    for(const auto e : res)
        cout << e << " ";
    cout << endl;

    cout << "no recur" << endl;
    auto res1 = postorderTraversal_noRecur(root);
    for(const auto e : res1)
        cout << e << " ";
    cout << endl;

    return 0;
}
