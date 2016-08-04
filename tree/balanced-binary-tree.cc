#include "../header.h"

/**Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode *root)
{
    if(!root)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode* root)
{
    if (!root)
        return true;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if (abs(lh - rh) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

class Solution {

public:
    bool isBalanced(TreeNode* root) {
        return balance(root)>=0;
    }
private :
    int balance(TreeNode *root) { // return depth if balanced, else -1
        if(!root) return 0;
        int ld=balance(root->left);
        int rd=balance(root->right);
        if(ld>=0 && rd>=0 && std::abs(ld-rd)<2) return 1+std::max(ld,rd);
        else return -1;
    }
};



