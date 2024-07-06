/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    vector<int>path;
    int flag=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        dfs(root,targetSum,0);
        if(flag)
            return true;
        return false;
    }
    void dfs(TreeNode*root,int target,int sum){
        if(flag)
            return;
        if(!root->left&&!root->right){
             if(sum+root->val==target){
                flag=1;
             }
             return;
        }
        if(root->left)
            dfs(root->left,target,sum+root->val);
        if(root->right)
            dfs(root->right,target,sum+root->val);
    }
};
// @lc code=end

