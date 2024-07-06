/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// class Solution {//本题链表没有头结点
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int cnt=1;
//         ListNode*p=head;
//         while(p->next!=nullptr){
//             cnt++;
//             p=p->next;
//         }
//         int tar=cnt-n;
//         p=head;
//         for(int i=1;i<tar;i++)
//             p=p->next;
//         if(cnt>1&&n!=cnt)
//             p->next=p->next->next;
//         else if(cnt==1){//表要清空
//             head=nullptr;
//         }
//         else{//删除第一个元素
//             head=p->next;
//         }
//         return head;
//     }
// };
class Solution {//快慢指针
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=1;
        ListNode*p=head;
        while(p->next!=nullptr){
            cnt++;
            p=p->next;
        }
        int tar=cnt-n;
        p=head;
        for(int i=1;i<tar;i++)
            p=p->next;
        if(cnt>1&&n!=cnt)
            p->next=p->next->next;
        else if(cnt==1){//表要清空
            head=nullptr;
        }
        else{//删除第一个元素
            head=p->next;
        }
        return head;
    }
};
// @lc code=end

