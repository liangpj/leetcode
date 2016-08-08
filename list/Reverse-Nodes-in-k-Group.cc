#include "../header.h"

/**Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* reverseKGroup_vec(ListNode* head, int k)
{
    if (k < 2) return head;
    ListNode *first = head, *cur;
    ListNode *newhead = new ListNode(-1);
    ListNode *tmp = newhead;
    vector<ListNode*> nodes;

    while(first) {
        cur = first;
        while(cur && nodes.size() != k) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        if (nodes.size() != k) {
            tmp->next = first;
            break;
        }
        for (int i = k-1; i >= 0; --i) {
            nodes[i]->next = nullptr;
            tmp->next = nodes[i];
            tmp = tmp->next;
        }
        nodes.clear();
        first = cur;
    }

    return newhead->next;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode *cur = head, *next;
    ListNode *newhead = new ListNode(-1);
    newhead->next = head;
    ListNode *tmp = newhead;

    int len = 0;
    //获取链表的长度
    while(cur) {
        ++len; cur = cur->next;
    }
    cur = head;
    while(len-k >= 0) {
        for(int i = 1; i < k; ++i) {
            next = cur->next;
            cur->next = next->next;
            next->next = tmp->next;
            tmp->next = next;
        }
        tmp = cur;
        cur = cur->next;
        len -= k;
    }
    return newhead->next;
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
//    vector<int> ivec = {1,2,3,4,5};
//    ListNode * head = creatList(ivec);
//    head = reverseKGroup(head, 2);
//    auto tmp = head;
//    while(tmp) {
//        cout << tmp->val << " ";
//        tmp = tmp->next;
//    }
//    cout << endl;
//
//    return 0;
//}
