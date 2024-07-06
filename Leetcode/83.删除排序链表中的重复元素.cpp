/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {//快慢指针
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode*p,*q;//q在前指向当前遍历到的元素，p在后指向删除后链表的最后一个元素
        p=head,q=head->next;
        while(q!=nullptr){
            if(p->val!=q->val){
                p=p->next;
                p->val=q->val;
            }
            q=q->next;
        }
        p->next=nullptr;//结尾要注意
        return head;
    }
};
// @lc code=end

