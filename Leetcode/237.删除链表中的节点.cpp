/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*p=node,*q=node->next;
        while(q->next){
            p->val=q->val;
            p=p->next,q=q->next;
        }
        p->val=q->val;
        p->next=nullptr;
    }
};
// @lc code=end

