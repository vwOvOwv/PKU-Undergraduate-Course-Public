/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int>ans;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     dfs(root);
    //     return ans;
    // }
    // void dfs(TreeNode* Node){
    //     if(Node)
    //         dfs(Node->left);
    //     if(Node)
    //         ans.push_back(Node->val);
    //     if(Node)
    //         dfs(Node->right);
    // }
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode*pointer=root;
        while(pointer||!st.empty()){
            if(pointer){
                st.push(pointer);
                pointer=pointer->left;
            }
            else{
                pointer=st.top();
                st.pop();
                ans.push_back(pointer->val);
                pointer=pointer->right;
            }
        }
        return ans;
    }
};
// @lc code=end

