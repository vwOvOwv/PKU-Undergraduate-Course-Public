/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode*dummy=new ListNode(-1,head);// 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode*cur=dummy,*l;
        int cnt=0;
        while(cur->next){
            cnt++;
            if(cnt==left){//找到起点
                l=cur;//l记录起点的前一个元素
                cur=cur->next;
                l->next=nullptr;//断开
                ListNode*p=nullptr,*q=cur,*tmp;//翻转的套路
                while(cnt!=right+1){
                    tmp=q->next;
                    q->next=p;
                    p=q;
                    q=tmp;
                    cnt++;
                }
                l->next=p;//重新接上
                cur->next=q;
                break;
            }
            else
                cur=cur->next;
        }
        return dummy->next;//头结点可能发生改变了，不能返回head!
    }
};
// @lc code=end

