#include "../header.h"

/**
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


static
void print(ListNode *head)
{
    auto tail = head;
    while(tail) {
        cout << tail->val << " ";
        tail = tail->next;
    }
    cout << endl;
}

static
int getListLength(ListNode *head) {
    if (!head)  return 0;
    auto tmp = head;
    int count = 0;
    while(tmp) {
        count += 1;
        tmp = tmp->next;
    }
    return count;
}


ListNode* reverseList(ListNode *head)
{
    ListNode *newhead = new ListNode(-1);
    //newhead->next = head;
    auto cur = head;
    ListNode *tmp;
    while(cur) {
        tmp = cur->next;
        cur->next = newhead->next;
        newhead->next = cur;
        cur = tmp;
    }
    head = newhead->next;
    delete newhead;
    return head;
}

void reorderList(ListNode *head)
{
    if (!head || !head->next) return;

    auto len = getListLength(head);
    ListNode *tail=head;
    for(int cnt = 1; cnt <= (len-1)/2; ++cnt) {
        tail = tail->next;
    }
    ListNode *newhead = tail->next;
    tail->next = NULL;
    newhead = reverseList(newhead);

    ListNode *cur = head;
    ListNode *rcur = newhead;
    ListNode *tmp;
    while(rcur) {
        tmp = rcur->next;
        rcur->next=cur->next;
        cur->next = rcur;
        rcur = tmp;
        cur = cur->next->next;
    }
    print(head);

}


int reorder_main()
{
    ListNode *head = new ListNode(1);
    vector<int> ivec = {2,3,4};//,5,6,7};
    auto tail = head;
    for(const auto e : ivec){
        auto tmp = new ListNode(e);
        tail->next = tmp;
        tail = tail->next;
    }
    reorderList(head);


    return 0;
}
