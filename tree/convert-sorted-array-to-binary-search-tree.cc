#include "../header.h"

/**Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order,
convert it to a height balanced BST
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static
TreeNode * build(vector<int> &nums, int start, int last)
{
    if (start > last) return nullptr;
    int mid = (last + start) / 2;
    TreeNode * root = new TreeNode(nums[mid]);
    root->left = build(nums, start, mid-1);
    root->right = build(nums, mid+1, last);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return build(nums, 0, nums.size()-1);
}

//int main()
//{
//    vector<int> nums = {1,2,3,4,5,6,7,8,9};
//    auto root = sortedArrayToBST(nums);
//}
