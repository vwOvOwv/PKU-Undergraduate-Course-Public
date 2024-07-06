/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode*ans=nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
    bool dfs(TreeNode*root,TreeNode*p,TreeNode*q){
        if(ans)
            return false;
        if(!root)
            return false;
        bool inLeft=dfs(root->left,p,q);
        bool inRight=dfs(root->right,p,q);
        if((inLeft&&inRight)||((root==p||root==q)&&(inLeft||inRight)))
            ans=root;
        return inLeft||inRight||root==p||root==q;
    }
};
// @lc code=end

