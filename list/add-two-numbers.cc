#include "../header.h"

/** Add Two Numbers
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes
contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int flag = 0;
    ListNode *newhead = new ListNode(-1);
    auto cur = newhead;
    auto cur1 = l1, cur2 = l2;

    while(cur1 && cur2) {
        int tmp = cur1->val + cur2->val + flag;
        cur->next = new ListNode(tmp%10);
        flag = tmp/10;
        cur = cur->next;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    cur1 = !cur1 ?  cur2 : cur1;
    while(cur1) {
        int tmp = cur1->val + flag;
        cur->next = new ListNode(tmp%10);
        flag = tmp/10;
        cur = cur->next; cur1 = cur1->next;
    }
    if (flag) cur->next = new ListNode(flag);

    return newhead->next;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode *l2, int flag)
{
    if (!l1 && !l2 && !flag)
        return nullptr;
    if (l1) {
        flag += l1->val;
        l1 = l1->next;
    }
    if (l2) {
        flag += l2->val;
        l2 = l2->next;
    }
    ListNode* node = new ListNode(flag%10);
    flag /= 10;
    node->next = addTwoNumbers(l1, l2, flag);
    return node;
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
//    vector<int> v1 = {2,4,3};
//    vector<int> v2 = {5,6,4};
//    auto l1 = creatList(v1);
//    auto l2 = creatList(v2);
////    auto l = addTwoNumbers(l1, l2);
//    auto l = addTwoNumbers(l1, l2, 0);
//    auto tmp = l;
//    while(tmp) {
//        cout << tmp->val << " ";
//        tmp = tmp->next;
//    }
//    cout << endl;
//
//    return 0;
//}
