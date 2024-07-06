/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ListNode*ptr=head;
                while(ptr!=slow){
                    /*
                    快慢指针的路程关系：2(a+b)=a+n(b+c)+b
                                           =a+(n+1)b+c
                                    a=(n-1)b+c=(n-1)(b+c)+c
                    */
                    slow=slow->next;
                    ptr=ptr->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end

