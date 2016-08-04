#include "../header.h"

/**Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*Time Limit Exceeded
*/
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head) return nullptr;
        int len = 0;
        auto tmp = head;
        while(tmp)
        {
            ++len;
            tmp = tmp->next;
        }
        return build(head, 0, len-1);
    }
private:
    int getValue(ListNode *head, int index)
    {
        auto tmp = head;
        int cnt = 0;
        while (cnt < index)
        {
            tmp = tmp->next;
            ++cnt;
        }
        return tmp->val;
    }

    TreeNode *build(ListNode *head, int start, int last)
    {
        if (start > last) return nullptr;
        int mid = (start + last) / 2;
        TreeNode * root = new TreeNode(getValue(head, mid));
        root->left = build(head, start, mid-1);
        root->right = build(head, mid+1, last);
        return root;
    }

};

vector<int> listToArray(ListNode *head)
{
    vector<int> ivec;
    auto tmp = head;
    while(tmp) {
        ivec.push_back(tmp->val);
        tmp = tmp->next;
    }
    return ivec;
}

static
TreeNode * build(vector<int> &nums, int start, int last)
{
    if (start > last) return nullptr;
    int mid = start + (last-start) / 2;
    TreeNode * root = new TreeNode(nums[mid]);
    root->left = build(nums, start, mid-1);
    root->right = build(nums, mid+1, last);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    auto nums = listToArray(head);
    return build(nums, 0, nums.size()-1);
}
//
//int main()
//{
//    vector<int> ivec = {2,3,4,5,6,7};
//    ListNode *head = new ListNode(1);
//    auto cur = head;
//    for(auto i : ivec)
//    {
//        auto tmp = new ListNode(i);
//        cur->next = tmp;
//        cur = tmp;
//    }
//    auto root = sortedListToBST(head);
//    return 0;
//
//}
