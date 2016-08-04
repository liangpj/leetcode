#include "../header.h"

/**Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

string tostring(int val);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void path_dfs(TreeNode *root, string str, vector<string> &res)
{
    if (!root) return;
    str += tostring(root->val);
    if (!root->left && !root->right) {
        res.push_back(str);
    }else {
        path_dfs(root->left, str+"->", res);
        path_dfs(root->right, str+"->", res);
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> path;
    string str = "";
    path_dfs(root, str, path);
    return path;
}

int binTree_path_main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    auto path = binaryTreePaths(root);
    for(auto e : path)
        cout << e << endl;

    return 0;
}

string tostring(int val)
{
    stringstream ss;
    ss << val;
    return ss.str();
}
