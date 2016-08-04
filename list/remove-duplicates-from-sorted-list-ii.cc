#include "../header.h"

/**Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if (!head) return head;
    ListNode * newhead = new ListNode(0);
    newhead->next = head;
    ListNode *prev = newhead, *cur = head;
    ListNode *next;
    bool flag = false;
    while(cur) {
        next = cur->next;
        if (next && cur->val == next->val) {
            flag = true;
            cur->next = next->next;
            delete next;
        }else {
            if (flag) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }else {
                prev = cur;
                cur = cur->next;
            }
            flag = false;
        }
    }
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

int main()
{
    vector<int> ivec = {1,1,1,2,3};
    auto head = creatList(ivec);
    head = deleteDuplicates(head);
    auto tmp = head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}
