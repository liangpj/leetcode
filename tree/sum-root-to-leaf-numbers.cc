#include "../header.h"

/**Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only,
each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 * Definition for a binary tree node.
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

void dfs(TreeNode *root, int sum, vector<int> &res)
{
    if (root){
        sum = sum*10 + root->val;
        if (!root->left && !root->right) {
//            cout << sum << " ";
            res.push_back(sum);
        }
        dfs(root->left, sum, res);
        dfs(root->right, sum, res);
    }
}

int sumNumbers(TreeNode* root)
{
    vector<int> path;
    dfs(root, 0, path);
    return accumulate(path.begin(), path.end(), 0);

}


int sumNumbers_main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int sum = 0;
    vector<int> res;
    dfs(root, sum, res);
    cout << endl << "--------" << endl;

    for(int i : res)
        cout << i << " ";
    cout << endl;

    cout << sumNumbers(root) << endl;


    return 0;
}
