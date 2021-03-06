#include "../header.h"

/**
Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some
starting node to any node in the tree along the parent-child connections.
The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root)
{

}


int binTree_max_path_main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << maxPathSum(root) << endl;

    return 0;
}
