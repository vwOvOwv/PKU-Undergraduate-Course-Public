/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxi=0;
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,1);
        return maxi;
    }
    void dfs(TreeNode*root,int depth){
        if(!root){
            maxi=max(depth-1,maxi);
            return;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
};
// @lc code=end

