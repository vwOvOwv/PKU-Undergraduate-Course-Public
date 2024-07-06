/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
class Solution {//利用二叉搜索树的中序有序性
public:
    vector<TreeNode*>inOrder;
    void recoverTree(TreeNode* root) {
        dfs(root);
        int n=inOrder.size();
        int cnt=0,x,y;
        for(int i=0;i<n-1;i++){
            if(inOrder[i]->val>inOrder[i+1]->val){
                if(cnt==0){//注意对交换结点分情况讨论
                    x=i;
                    y=i+1;
                }
                else if(cnt==1){
                    y=i+1;
                }
                cnt++;
            }
        }
        int tmp=inOrder[x]->val;
        inOrder[x]->val=inOrder[y]->val;
        inOrder[y]->val=tmp;
    }
    void dfs(TreeNode*root){
        if(root){
            dfs(root->left);
            inOrder.push_back(root);
            dfs(root->right);
        }
    }
};
// @lc code=end

