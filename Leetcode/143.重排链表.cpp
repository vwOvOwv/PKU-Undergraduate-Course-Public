/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {//找中点，翻转后一半链表再合并
        if(!head||!head->next)
            return;
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*q=slow->next,*p=nullptr;
        slow->next=nullptr;
        while(q){
            ListNode*tmp=q->next;
            q->next=p;
            p=q;
            q=tmp;
        }
        q=head;//p就是翻转后的头结点
        while(p&&q){
            ListNode*tmp=q->next;
            q->next=p;
            q=tmp;
            tmp=p->next;
            p->next=q;
            p=tmp;
        }
    }
};
// @lc code=end

