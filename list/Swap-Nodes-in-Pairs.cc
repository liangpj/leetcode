#include "../header.h"

/**Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list,
only nodes itself can be changed.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
    ListNode *first = head;
    ListNode *second, *cur;
    ListNode *newhead= new ListNode(-1);
    ListNode *tmp = newhead;

    while(first) {
        second = first->next;
        cur = second ? second->next : nullptr;
        if (second) {
            tmp->next = second;
            tmp = tmp->next;
        }
        tmp->next = first;
        tmp = tmp->next;
        first = cur;
    }
    tmp->next = nullptr;
    head = newhead->next;
    delete newhead;
    return head;
}

static
ListNode * creatList(vector<int> &ivec)
{
    ListNode * head = new ListNode(ivec[0]);
    auto cur = head;
    for(int i = 1; i < ivec.size(); ++i) {
        cur->next = new ListNode(ivec[i]);
        cur = cur->next;
    }
    return head;
}


//int main()
//{
//    vector<int> ivec = {1,2,3,4};
//    ListNode * head = creatList(ivec);
//    head = swapPairs(head);
//    auto tmp = head;
//    while(tmp) {
//        cout << tmp->val << " ";
//        tmp = tmp->next;
//    }
//    cout << endl;
//
//    return 0;
//}
