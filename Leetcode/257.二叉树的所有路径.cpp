/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string>rec;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return rec;
    }
    void dfs(TreeNode*root,string ans){
        if(root){
            //int转string
            if(root->val<0)
                ans.push_back('-');
            int tmp=abs(root->val);
            string num;
            while(tmp){
                num.push_back(tmp%10+'0');
                tmp/=10;
            }
            for(int i=num.size()-1;i>=0;i--)
                ans.push_back(num[i]);
            if(root->left){
                ans+="->";
                dfs(root->left,ans);
                ans.pop_back();
                ans.pop_back();
            }
            if(root->right){
                ans+="->";
                dfs(root->right,ans);
                ans.pop_back();
                ans.pop_back();
            }
        }
        if(root&&!root->left&&!root->right)//是叶结点
            rec.push_back(ans);
    }   
};
// @lc code=end

