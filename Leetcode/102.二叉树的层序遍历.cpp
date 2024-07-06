/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int> >q;
        int pre=-1;//记录前一层的深度
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode*p=q.front().first;
            int depth=q.front().second;
            q.pop();
            if(depth!=pre){
                pre=depth;
                ans.push_back(vector<int>(1,p->val));
            }
            else{
                ans.back().push_back(p->val);
            }
            if(p->left)
                q.push(make_pair(p->left,depth+1));
            if(p->right)
                q.push(make_pair(p->right,depth+1));
        }
        return ans;
    }
};
// @lc code=end

