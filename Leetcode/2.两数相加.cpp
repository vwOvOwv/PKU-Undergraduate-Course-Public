/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=new ListNode(),*cur=head;
        ListNode*p=l1,*q=l2;
        while(p&&q){
            int res=p->val+q->val;
            ListNode*tmp=new ListNode(res);
            cur->next=tmp;
            cur=cur->next;
            p=p->next;
            q=q->next;
        }
        while(p){
            ListNode*tmp=new ListNode(p->val);
            cur->next=tmp;
            cur=cur->next;
            p=p->next;
        }
        while(q){
            ListNode*tmp=new ListNode(q->val);
            cur->next=tmp;
            cur=cur->next;
            q=q->next;
        }
        cur=head->next;
        while(cur){
            if(cur->val>=10){
                cur->val-=10;
                if(cur->next)
                    cur->next->val++;
                else{
                    ListNode*tmp=new ListNode(1);
                    cur->next=tmp;
                }
            }
            cur=cur->next;
        }
        return head->next;
    }
};
// @lc code=end

