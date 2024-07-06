/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return compare(root,root);
    }
    bool compare(TreeNode*l,TreeNode*r){
        if(!l)
            return r==nullptr;
        if(!r)
            return l==nullptr;
        if(l->val!=r->val)
            return false;
        return compare(l->left,r->right)&&compare(l->right,r->left);
    }
};
// @lc code=end

