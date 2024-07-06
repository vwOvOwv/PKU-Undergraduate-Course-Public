/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int> >q;
        int pre=-1;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode*p=q.front().first;
            int depth=q.front().second;
            q.pop();
            if(depth!=pre){
                pre=depth;
                ans.push_back(vector<int>(1,p->val));
            }
            else
                ans.back().push_back(p->val);
            if(!depth%2){
                
            }
        }
    }
};
// @lc code=end

