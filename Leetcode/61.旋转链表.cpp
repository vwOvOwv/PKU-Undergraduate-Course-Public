/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {//循环
        if(head==nullptr||head->next==nullptr)
            return head;
        int length=1;
        ListNode*cur=head;
        while(cur->next!=nullptr){
            cur=cur->next;
            length++;
        }
        cur->next=head;
        int cnt=length-k%length;//从左向右数
        while(cnt--){
            head=head->next;
        }
        cur=head;
        length--;
        while(length--){
            cur=cur->next;
        }
        cur->next=nullptr;
        return head;
    }
};
// @lc code=end

