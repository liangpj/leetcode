#include "../header.h"

/**Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return ;
        queue<TreeLinkNode *> que;
        que.push(root);
        que.push(nullptr);

        while(!que.empty()) {
            auto node = que.front(); que.pop();
            if (node == nullptr && que.size() > 0)
                que.push(nullptr);
            else if (node != nullptr) {
                node->next = que.front();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
    }
};

static
void connect(TreeLinkNode *root)
{
    if (!root)
        return ;
    //用来保存每层的第一个节点(最左节点)
    TreeLinkNode *head = root; //下一层最左边的节点
    TreeLinkNode *prev = nullptr; //下一层前一个节点
    TreeLinkNode *cur = nullptr; //上一层当前的节点

    while (head) {
        cur = head;
        head = prev = nullptr;
        while (cur) {
            //左子树
            if (cur->left) {
                if (prev)
                    prev->next = cur->left;
                else
                    head = cur->left;
                prev = cur->left;
            }

            //右子数
            if (cur->right) {
                if (prev)
                    prev->next = cur->right;
                else
                    head = cur->right;
                prev = cur->right;
            }
            //移动到当前层的下一个节点
            cur = cur->next;
        }
    }
}
