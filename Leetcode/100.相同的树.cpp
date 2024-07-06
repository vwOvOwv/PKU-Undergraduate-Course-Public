/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)  {
        if(!p)
            return q==nullptr;
        if(!q)
            return p==nullptr;
        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//同时完成向下搜索和比较
    }
    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {//同时遍历两棵树
        if(!p&&q)
            return false;
        if(!q&&p)
            return false;
        stack<TreeNode*>st1,st2;
        TreeNode *pointer1=p,*pointer2=q;
        st1.push(nullptr);
        st2.push(nullptr);
        while(pointer1&&pointer2){
            if(pointer1->val!=pointer2->val)
                return false;
            if(pointer1->right&&pointer2->right){
                st1.push(pointer1->right);
                st2.push(pointer2->right);
            }
            else if(!pointer1->right&&!pointer2->right){

            }
            else
                return false;
            if(pointer1->left&&pointer2->left){
                pointer1=pointer1->left;
                pointer2=pointer2->left;
            }
            else if(!pointer1->left&&!pointer2->left){
                pointer1=st1.top();
                st1.pop();
                pointer2=st2.top();
                st2.pop();
            }
            else
                return false;
        }
        return true;
    }
    */
};
// @lc code=end

