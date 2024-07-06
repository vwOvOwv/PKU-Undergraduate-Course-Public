/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {//暴力破解
        if(!head||!head->next)
            return head;
        ListNode* head1=new ListNode;
        ListNode* head2=new ListNode;
        ListNode*p=head,*cur1=head1,*cur2=head2;
        while(p){
            if(p->val<x){
                ListNode*tmp=new ListNode(p->val);
                cur1->next=tmp;
                cur1=cur1->next;
            }
            else{
                ListNode*tmp=new ListNode(p->val);
                cur2->next=tmp;
                cur2=cur2->next;
            }
            p=p->next;
        }
        cur1->next=head2->next;
        return head1->next;
    }
};
// @lc code=end

