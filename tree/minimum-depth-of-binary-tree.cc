#include "../header.h"

/** Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.
*/

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(!root->left)
            return  1 + minDepth(root->right);
        else if(!root->right)
            return 1 + minDepth(root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
