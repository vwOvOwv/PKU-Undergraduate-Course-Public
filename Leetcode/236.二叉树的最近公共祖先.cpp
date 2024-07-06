/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //递归
    TreeNode*ans=nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
    bool dfs(TreeNode*root,TreeNode*p,TreeNode*q){
        if(ans)
            return false;
        if(!root)
            return false;
        bool inLeft=dfs(root->left,p,q);
        bool inRight=dfs(root->right,p,q);
        if((inLeft&&inRight)||((root==p||root==q)&&(inLeft||inRight)))
            ans=root;
        return inLeft||inRight||root==p||root==q;
    }

    //存路径
   unordered_map<TreeNode*,TreeNode*>hashtable;
   unordered_map<TreeNode*,bool>visited;
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        stack<TreeNode*>st;
        st.push(nullptr);
        TreeNode*pointer=root;
        hashtable[root]=nullptr;
        while(pointer){
            if(pointer->right){
                hashtable[pointer->right]=pointer;
                st.push(pointer->right);
            }
            if(pointer->left){
                hashtable[pointer->left]=pointer;
                pointer=pointer->left;
            }
            else{
                pointer=st.top();
                st.pop();
            }
        }
        while(p){
            visited[p]=1;
            p=hashtable[p];
        }
        while(q){
            if(visited[q])
                return q;
            q=hashtable[q];
        }
        return nullptr;
   }
};
// @lc code=end

