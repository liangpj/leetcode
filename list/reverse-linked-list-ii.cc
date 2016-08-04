#include "../header.h"

/** Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode *cur = head;
    ListNode *next;
    ListNode *newhead = new ListNode(-1);

    newhead->next = head;
    int i = 1;
    while (i < m) {
        newhead = cur;
        cur = cur->next;
        ++i;
    }
    newhead->next = nullptr;

    while(i <= n) {
        next = cur->next;
        cur->next = newhead->next;
        newhead->next = cur;
        ++i;
        cur = next;
    }
    cur = head;
    while(cur->next)
        cur = cur->next;
    cur->next = next;

    return newhead->next;
}

//int main()
//{
//    ListNode * head = new ListNode(1);
//    vector<int> ivec = {2,3,4,5};
//    auto cur = head;
//    for(int i : ivec) {
//        auto tmp = new ListNode(i);
//        cur->next = tmp;
//        cur = tmp;
//    }
//
//    head = reverseBetween(head, 1, 4);
//    cur = head;
//    while(cur) {
//        cout << cur->val << " ";
//        cur = cur->next;
//    }
//    cout << endl;
//
//    return 0;
//}
