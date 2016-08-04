#include "../header.h"

/** linked-list-cycle
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle_1(ListNode *head)
{
    set<ListNode*> visit;
    ListNode *tmp = head;
    while(tmp) {
        auto ret = visit.insert(tmp);
        if (ret.second == false)
            return true;
        tmp = tmp->next;
    }
    return false;
}

/* 使用两个指针slower, faster指向同一链表
* 一个指针移动的快一些，另外一个指针移动的慢一些
* 如果这个链表有环的话，那么这两个指针一定会在某一点相遇
**/
bool hasCycle(ListNode *head)
{
    if(!head)  return false;
    ListNode* faster = head;
    ListNode* slower = head;
    while(faster->next != NULL && faster->next->next != NULL) {
        faster = faster->next->next;    //快指针一次移动两步
        slower = slower->next;  //慢指针一次移动一步
        if (faster == slower)
            return true;
    }
    return false;
}


int listcycle()
{
    ListNode *head = new ListNode(1);
    auto first = new ListNode(2);
    head->next = first;

    vector<int> ivec = {3,4,5};
    auto tail = first;
    for(const auto e : ivec) {
        tail->next = new ListNode(e);
        tail = tail->next;
    }
    tail = head;
    while(tail->next)
        tail = tail->next;
    tail->next = first;
    cout << hasCycle(head) << endl;

    return 0;
}
