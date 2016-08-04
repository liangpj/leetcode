#include "../header.h"

/**
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[1,2,3].
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode*> nodeSt;
    auto node = root;
    while (node || !nodeSt.empty()) {
        while(node) {
            res.push_back(node->val);
            nodeSt.push(node);
            node = node->left;
        }
        if (!nodeSt.empty()) {
            node = nodeSt.top()->right;
            nodeSt.pop();
        }
    }
    return res;
}


int preOrder()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    auto res = preorderTraversal(root);
    for(const auto e : res)
        cout << e << " ";
    cout << endl;

    return 0;
}
