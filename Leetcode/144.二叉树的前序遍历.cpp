/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    //解法1:递归
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode*root){
        if(root){
            ans.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }

    //解法2：模拟递归栈（由中序遍历修改而来）
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode*pointer=root;
        while(pointer||!st.empty()){
            if(pointer){
                ans.push_back(pointer->val);
                st.push(pointer->right);//先不考虑子树是否为空
                pointer=pointer->left;
            }
            else{
                pointer=st.top();
                st.pop();
            }
        }
        return ans;
    }

   //解法3:模拟递归栈（前序遍历）
   vector<int>ans;
   vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode*pointer=root;
        st.push(nullptr);//监视哨
        while(pointer){
            ans.push_back(pointer->val);
            if(pointer->right)
                st.push(pointer->right);
            if(pointer->left)
                pointer=pointer->left;
            else{
                pointer=st.top();//设立了监视哨，否则最后会访问空栈
                st.pop();
            }
        }
        return ans;
   }
};
// @lc code=end

