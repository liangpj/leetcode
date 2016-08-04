#include "../header.h"

/**
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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

static
void print(ListNode *head)
{
    auto tmp = head;
    while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //定义一个临时的头结点
    ListNode * tmpHead = new ListNode(-1);

    auto tmp = tmpHead;
    auto lnode = l1, rnode = l2;
    while(lnode && rnode) {
        if (lnode->val < rnode->val) {
            tmp->next = lnode;
            lnode = lnode->next;
        } else {
            tmp->next = rnode;
            rnode = rnode->next;
        }
        tmp = tmp->next;
    }
    if (lnode)
        tmp->next = lnode;
    if (rnode)
        tmp->next = rnode;
    return tmpHead->next;
}

static
ListNode * insert(ListNode *head, vector<int> ivec)
{
    auto tail = head;
    for(const auto i : ivec) {
        auto tmp = new ListNode(i);
        tail->next = tmp;
        tail = tail->next;
    }
    return head;
}


int merge_sort_list_main()
{
    vector<int> ivec1 = {1,3,5,6,7};
    vector<int> ivec2 = {2,3,4,8,9};
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);

    l1 = insert(l1, ivec1);
    l2 = insert(l2, ivec2);

    auto head = mergeTwoLists(l1, l2);
    print(head);

    return 0;
}


