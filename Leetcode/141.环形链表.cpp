/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
class Solution {//快慢指针,龟兔赛跑
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)//空表特判
            return false;
        ListNode *slow,*fast;
        slow=fast=head;
        while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            //快慢指针相对速度是1，所以不会错开
            if(fast==slow)
                return true;
        }
        return false;
    }
};
// @lc code=end

