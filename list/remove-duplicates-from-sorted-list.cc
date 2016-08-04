#include "../header.h"


/**Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur){
            if (cur->val == prev->val){
                auto tmp = cur;
                prev->next = cur->next;
                delete cur;
                cur = tmp->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }

};

//int main()
//{
//    ListNode *head = new ListNode(1);
//    head->next = new ListNode(1);
//    head->next = new ListNode(1);
////    head->next->next = new ListNode(3);
////    head->next->next = new ListNode(3);
//
//    head = deleteDuplicates(head);
//    auto tmp = head;
//    while(tmp) {
//        cout << tmp->val << " ";
//        tmp = tmp->next;
//    }
//    cout << endl;
//
//    return 0;
//}
