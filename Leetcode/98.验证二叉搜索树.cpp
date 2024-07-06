/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution {//中序遍历
public:
    int flag=1;
    long long pre=-2147483648-1;//mark
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return flag;
    }
    void dfs(TreeNode*root){
        if(flag==0)
            return;
        if(root)
            dfs(root->left);
        if(root){
            if(root->val<=pre){
                flag=0;
                return;
            }
            else
                pre=root->val;
        }
        if(root)
            dfs(root->right);
    }
};
// @lc code=end

