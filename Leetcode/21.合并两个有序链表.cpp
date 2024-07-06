/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*ListNode*p=list1;
        ListNode*q=list2;
        if(p==nullptr)
            return list2;
        else if(q==nullptr)
            return list1;
        else{
            while(p!=nullptr){
                q=list2;//对每一个p都从头开始枚举q
                if(p->val<q->val){//在头结点前插入
                    ListNode*tmp=new ListNode(p->val);
                    tmp->next=q;
                    list2 =tmp;
                }
                else{
                    while(q->next!=nullptr){
                        if(p->val>=q->val&&p->val<q->next->val){//在两个结点之间插入
                            ListNode*tmp=new ListNode(p->val);
                            tmp->next=q->next;
                            q->next=tmp;
                            break;
                        }
                        q=q->next;
                    }
                    if(q->next==nullptr){//在尾结点后插入
                        ListNode*tmp=new ListNode(p->val);
                        q->next=tmp;
                    }
                }
                p=p->next;
            }
            return list2;
        }*/
        ListNode*dummy=new ListNode;
        ListNode*prev=dummy,*p=list1,*q=list2;//prev->next标记合并后数组末尾
        while(p&&q){
            if(p->val<=q->val){
                prev->next=p;
                p=p->next;
                prev=prev->next;
            }
            else{
                prev->next=q;
                q=q->next;
                prev=prev->next;
            }
        }
        if(p)
            prev->next=p;
        if(q)
            prev->next=q;
        return dummy->next;
    }
};
// @lc code=end

