#include "../header.h"

/**Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> rightSideView_que(TreeNode* root)
{
    vector<int> res;

    if (!root) return res;
    queue<TreeNode *> que;
    que.push(root);
    que.push(nullptr);

    while(!que.empty()) {
        auto node = que.front(); que.pop();
        if (node && !que.front())
            res.push_back(node->val);
        if (!node && que.size() > 0)
            que.push(nullptr);
        if (node && node->left) que.push(node->left);
        if (node && node->right) que.push(node->right);
    }
    return res;
}

void sideView(TreeNode *root, size_t level, vector<int> &vec)
{
    if (!root)
        return ;
    if (vec.size() == level)
        vec.push_back(root->val);
    sideView(root->right, level+1, vec);
    sideView(root->left, level+1, vec);
}

vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    sideView(root, 0, res);
    return res;
}

//
//int main()
//{
//    TreeNode *root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->right = new TreeNode(5);
//    root->right->right = new TreeNode(4);
//
//    auto res = rightSideView(root);
//    for_each(res.begin(), res.end(), [](int a) {cout << a << " ";});
//    cout << endl;
//
//    return 0;
//}
