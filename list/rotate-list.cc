#include "../header.h"
/**
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given1->2->3->4->5->NULLand k =2,
return4->5->1->2->3->NULL.
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



ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next) return head;
    int len = 0;

    //获取链表的长度
    auto tmp = head;
    while(tmp) {
        ++len;
        tmp = tmp->next;
    }

    k = k%len;
    if (!k) return head;

    int leftlen = len - k;
    tmp = head;
    ListNode *roteHead;
    for(int i = 1; i < leftlen; ++i)
        tmp = tmp->next;
    roteHead = tmp->next;
    tmp->next = nullptr;

    tmp = roteHead;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = head;

    return roteHead;
}

int rotate_list_main()
{
    ListNode *head = new ListNode(1);
    vector<int> ivec = {2,3};
    auto tail = head;
    for(int i : ivec) {
        auto tmp = new ListNode(i);
        tail->next = tmp;
        tail= tail->next;
    }


    head = rotateRight(head, 4);


    return 0;
}
