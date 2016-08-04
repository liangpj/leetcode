#include "../header.h"

/**Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
我们可以使用中序遍历去序列化一颗二叉树，
如果二叉树是一颗二叉搜索树那么中序遍历的结果就是
一个升序的序列表。因此我们可以使用一个全局变量prev指向
序列表中前一个节点的引用来进行判断
*/
bool inorder(TreeNode *root, TreeNode *prev)
{
    if (!root) return true;
    if (!inorder(root->left, prev)) return false;
    if (prev && prev->val >= root->val) return false;
    prev = root;
    return inorder(root->right, prev);
}

bool isValidBST(TreeNode* root)
{
    TreeNode* prev = nullptr;
    return inorder(root, prev);
}


//int main()
//{
//    TreeNode *root = new TreeNode(10);
//    root->left = new TreeNode(5);
//    root->right = new TreeNode(15);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(20);
//    cout << isValidBST(root) << endl;
//
//    return 0;
//}
