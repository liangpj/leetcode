#include "../header.h"

/**
Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.
Follow up:
Can you solve it without using extra space?

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode *detectCycle1(ListNode *head)
{
    set<ListNode*> nodeset;
    auto tmp = head;
    while(tmp) {
        auto ret = nodeset.insert(tmp);
        if (ret.second == false) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

ListNode *detectCycle(ListNode *head)
{
    if(!head)  return NULL;
    ListNode *faster=head;
    ListNode *slower=head;
    bool flag = false;
    while(faster->next != NULL && faster->next->next != NULL)
    {
        faster = faster->next->next;
        slower = slower->next;
        if (faster == slower) {
            flag = true;
            break;
        }
    }
    if (flag) {
        slower = head;
        while(slower != faster) {
            slower = slower->next;
            faster = faster->next;
        }
        return slower;
    }
    return NULL;
}


int list_cycle2()
{
    ListNode *head = new ListNode(1);
    auto first = new ListNode(2);
    head->next = first;

    vector<int> ivec = {3,4,5};
    auto tail = first;
    for(const auto e : ivec)
    {
        tail->next = new ListNode(e);
        tail = tail->next;
    }
    tail = head;
    while(tail->next)
        tail = tail->next;
    tail->next = first;
    cout << detectCycle(head)->val << endl;
    return 0;
}
