/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    //解法1：递归
    // vector<int>ans;
    // vector<int> postorderTraversal(TreeNode* root) {
    //     dfs(root);
    //     return ans;
    // }
    // void dfs(TreeNode* root){
    //     if(root){
    //         dfs(root->left);
    //         dfs(root->right);
    //         ans.push_back(root->val);
    //     }
    // }
    //解法2:模拟工作栈
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root){
        stack<pair<TreeNode*,char> >st;
        TreeNode*pointer=root;
        while(pointer||!st.empty()){
            if(pointer){
                st.push(make_pair(pointer,'L'));
                pointer=pointer->left;
            }
            else{
                pair<TreeNode*,char> tmp=st.top();
                st.pop();
                pointer=tmp.first;
                if(tmp.second=='L'){
                    st.push(make_pair(pointer,'R'));
                    pointer=pointer->right;
                }
                else{
                    ans.push_back(pointer->val);
                    pointer=nullptr;//重要的
                }
            }
        }
        return ans;
    }
};
// @lc code=end

