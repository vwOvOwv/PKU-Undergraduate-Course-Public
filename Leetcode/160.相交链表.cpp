/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
class Solution {//先将起点对齐之后一起向前走看是否相遇
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA,*q=headB;
        int cntA=1,cntB=1;
        while(p->next!=nullptr){
            cntA++;
            p=p->next;
        }
        while(q->next!=nullptr){
            cntB++;
            q=q->next;
        }
        p=headA,q=headB;
        int gap;
        if(cntA>=cntB){
            gap=cntA-cntB;
            while(gap--)
                p=p->next;
        }
        else{
            gap=cntB-cntA;
            while(gap--)
                q=q->next;
        }
        while(p!=nullptr){
            if(p==q)
                return p;
            p=p->next;
            q=q->next;
        }
        return p;
    }
};
// @lc code=end

