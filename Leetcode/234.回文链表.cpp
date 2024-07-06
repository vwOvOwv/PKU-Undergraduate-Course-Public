/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {//翻转一半链表
        if(head->next==nullptr)
            return true;
        ListNode*p=nullptr,*q=head;
        int length=1;
        while(q->next!=nullptr){
            q=q->next;
            length++;
        }
        q=head;
        for(int i=1;i<=length/2;i++){
            ListNode*tmp=q->next;
            q->next=p;
            p=q;
            q=tmp;

        }
        if(length%2)
            q=q->next;
        while(p!=nullptr&&q!=nullptr){
            if(p->val!=q->val)
                return false;   
            p=p->next;
            q=q->next;
        }
        return true;
    }
};
// @lc code=end

