/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*tmp,*p,*q;
        tmp=dummy;
        while(tmp&&tmp->next&&tmp->next->next){
            p=tmp->next;
            q=p->next;
            p->next=q->next;
            q->next=p;
            tmp->next=q;
            tmp=p;
        }
        return dummy->next;
    }
};
// @lc code=end

