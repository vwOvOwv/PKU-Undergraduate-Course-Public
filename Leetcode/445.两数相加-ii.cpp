/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
        stack<int>st1,st2;//由于数字在链表中的顺序和我们计算加法的顺序相反，因此可以用栈颠倒数字计算
        ListNode *p=l1,*q=l2,*cur=nullptr;
        while(p){
            st1.push(p->val);
            p=p->next;
        }
        while(q){
            st2.push(q->val);
            q=q->next;
        }
        int carry=0;//记录是否有进位
        while(!st1.empty()&&!st2.empty()){
            int a=st1.top(),b=st2.top();
            int num=a+b+carry;
            carry=0;
            if(num>=10){
                carry=1;
                num-=10;
            }
            ListNode*tmp=new ListNode(num,cur);
            cur=tmp;
            st1.pop();
            st2.pop();
        }
        while(!st1.empty()){//还有多的数字
            ListNode*tmp=new ListNode(st1.top()+carry,cur);//可能还有进位
            carry=(tmp->val>=10)?1:0;
            if(carry)tmp->val-=10;
            cur=tmp;
            st1.pop();
        }
        while(!st2.empty()){
            ListNode*tmp=new ListNode(st2.top()+carry,cur);
            carry=(tmp->val>=10)?1:0;
            if(carry)tmp->val-=10;
            cur=tmp;
            st2.pop();
        }
        if(carry){
            ListNode*tmp=new ListNode(1,cur);
            cur=tmp;
        }
        return cur;
    }
};
// @lc code=end

