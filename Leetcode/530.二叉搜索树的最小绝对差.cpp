/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int mini=INT_MAX,pre=-1;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return mini;
    }
    void dfs(TreeNode*root){
        if(root){
            dfs(root->left);
            if(pre==-1)
                pre=root->val;
            else{
                mini=min(mini,abs(pre-root->val));
                pre=root->val;
            }
            dfs(root->right);
        }
    }
};
// @lc code=end

