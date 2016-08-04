#include "../header.h"

/**Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths
where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void findPath(TreeNode * root, int sum, vector<int> curr, vector<vector<int>> &paths)
{
    if (!root)
        return ;
    curr.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
        paths.push_back(curr);
//        curr.pop_back();
        return ;
    }else {
        findPath(root->left, sum - root->val, curr, paths);
        findPath(root->right, sum - root->val, curr, paths);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> paths;
    vector<int> path;
    findPath(root, sum, path, paths);
    return paths;
}

//int main()
//{
//    TreeNode *root = new TreeNode(5);
//    root->left = new TreeNode(4);
//    root->left->left = new TreeNode(11);
//    root->left->left->left = new TreeNode(7);
//    root->left-> left->right = new TreeNode(2);
//    root->right = new TreeNode(8);
//    root->right->left = new TreeNode(13);
//    root->right->right = new TreeNode(4);
//    root->right->right->right = new TreeNode(1);
//    root->right->right->left = new TreeNode(5);
//
//    auto res = pathSum(root, 22);
//    for(auto e : res) {
//        for (auto i : e)
//            cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}
