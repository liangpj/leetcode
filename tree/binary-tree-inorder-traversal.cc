#include "../header.h"

/**Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> st;
    auto node = root;
    while(node || !st.empty()) {
        while(node) {
            st.push(node);
            node = node->left;
        }
        if (!st.empty()) {
            node = st.top();
            st.pop();
            res.push_back(node->val);
            node = node->right;
        }
    }
    return res;
}

//int main()
//{
//    TreeNode *root = new TreeNode(10);
//    root->left = new TreeNode(5);
//    root->right = new TreeNode(15);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(20);
//
//    auto res = inorderTraversal(root);
//    for(auto e : res)
//        cout << e << " ";
//    cout << endl;
//
//    return 0;
//}
