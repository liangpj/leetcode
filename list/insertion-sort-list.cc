#include "../header.h"

/**Sort a linked list using insertion sort.

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

ListNode *insertionSortList(ListNode *head)
{
    if (!head || !head->next) return head;

    ListNode *newhead = new ListNode(-1);
    newhead->next = head;

    ListNode *prev, *cur, *tail;
    ListNode *pp, *tmp;
    prev = head;
    cur = head->next;
    while(cur != NULL) {
        prev->next = cur->next;
        tail = cur->next;

        pp = newhead;
        tmp = newhead->next;

        while(tmp != tail) {
            if(tmp->val < cur->val) {
                pp = tmp;
                tmp = tmp->next;
            } else {
                cur->next = pp->next;
                pp->next = cur;
                break;
            }
        }
        if (tmp == tail) {
            cur->next = pp->next;
            pp->next = cur;
            prev = cur;
        }
        cur = tail;
    }

    head = newhead->next;
    delete newhead;
    return head;
}

int insertSortList()
{
    ListNode *head = new ListNode(10);
    vector<int> ivec = {9,8,6,4,2,1};//{7,3,5,9,1,0,3,2,4};
    ListNode *tail = head;
    for(const auto e : ivec)
    {
        auto tmp = new ListNode(e);
        tail->next = tmp;
        tail = tmp;
    }
    head =insertionSortList(head);
    tail = head;
    while(tail !=NULL)
    {
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout << endl;

    return 0;
}
