#include "../header.h"

/**Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

ListNode* reverse(ListNode * head)
{
    ListNode* newhead = new ListNode(-1);
    auto tmp = head, next = tmp->next;
    while(tmp) {
        next = tmp->next;
        tmp->next = newhead->next;
        newhead->next = tmp;
        tmp = next;
    }
    head = newhead->next;
    delete newhead;
    return head;
}

bool isPalindrome(ListNode* head)
{
    int len = 0;
    auto tmp = head;
    while(tmp) {
        ++len;
        tmp = tmp->next;
    }

    ListNode *posthead;
    tmp = head;
    for (int i = 1;i < (len+1)/2; ++i)
        tmp = tmp->next;
    posthead = tmp->next;
    tmp->next = NULL;
    posthead = reverse(posthead);

    auto prev = head, post = posthead;
    while(prev && post) {
        if (prev-> val != post->val)
            return false;
        prev = prev->next;
        post = post->next;
    }
    return true;
}


int Palin_List_main()
{
    ListNode *head = new ListNode(1);
    vector<int> ivec = {2,3,2,1};

    auto cur = head;
    for(int i : ivec) {
        auto tmp = new ListNode(i);
        cur->next = tmp;
        cur = cur->next;
    }

    cout << isPalindrome(head) << endl;

    return 0;
}
