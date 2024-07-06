/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(height(root->left)-height(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
    int height(TreeNode*root){
        int ans=0;
        if(!root)
            return ans;
        ans=height(root->left);
        ans=max(ans,height(root->right));
        return ans+1;
    }
};
// @lc code=end

