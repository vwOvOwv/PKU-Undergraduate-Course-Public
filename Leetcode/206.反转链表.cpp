/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // ListNode* reverseList(ListNode* head) {//双指针
    //     ListNode*p=nullptr,*q=head;
    //     while(q!=nullptr){
    //         ListNode*tmp=q->next;//指针的维护！！！
    //         q->next=p;
    //         p=q;q=tmp;
    //     }
    //     return p;
    // }

    //递归，与双指针类似
    ListNode* reverse(ListNode*p,ListNode*q){
        if(q==nullptr)//到达末尾、
            return p;
        ListNode*tmp=q->next;
        q->next=p;
        return reverse(q,tmp);
    }
    ListNode* reverseList(ListNode* head){
        return reverse(nullptr,head);//初始位置也与双指针相同
    }
};
// @lc code=end

