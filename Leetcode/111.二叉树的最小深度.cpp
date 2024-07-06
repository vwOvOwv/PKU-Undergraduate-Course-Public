/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int mini;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode*p=q.front().first;
            int depth=q.front().second;
            q.pop();
            if(!p->left&&!p->right){
                mini=depth;
                break;
            }
            if(p->left)
                q.push(make_pair(p->left,depth+1));
            if(p->right)
                q.push(make_pair(p->right,depth+1));
        }
        return mini+1;
    }
};
// @lc code=end

