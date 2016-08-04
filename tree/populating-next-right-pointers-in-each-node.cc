#include "../header.h"

/**Populating Next Right Pointers in Each Node
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree
(ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
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

class Solution
{
public:
    //使用两个队列进行求解
    void connect(TreeLinkNode *root)
    {
        if (!root) return;
        queue<TreeLinkNode *> first;
        queue<TreeLinkNode *> second;
        first.push(root);

        while(!first.empty() || !second.empty()){
            while(!first.empty()){
                auto node = first.front();
                first.pop();
                if (!first.empty())
                    node->next = first.front();
                if (node->left) second.push(node->left);
                if (node->right) second.push(node->right);
            }
            while(!second.empty()){
                auto node = second.front();
                second.pop();
                if (!second.empty())
                    node->next = second.front();
                if (node->left) first.push(node->left);
                if (node->right) first.push(node->right);
            }
        }
    }
};

/*使用队列的方法进行层次遍历
*/
void connect_que(TreeLinkNode *root)
{
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

//int main()
//{
//    TreeLinkNode *root = new TreeLinkNode(0);
//    connect(root);
//    return 0;
//}
