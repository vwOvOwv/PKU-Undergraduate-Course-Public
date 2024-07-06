/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int,int>hash;
    TreeNode*myBuildTree(vector<int> inorder,vector<int>postorder,int postleft,int postright,int inleft,int inright){
        //倒着从后序序列找根结点
        if(postleft>postright)
            return nullptr;
        TreeNode*root=new TreeNode(postorder[postright]);
        int root_in_pos=hash[postorder[postright]];
        root->left=myBuildTree(inorder,postorder,postleft,postleft+root_in_pos-inleft-1,inleft,root_in_pos-1);
        root->right=myBuildTree(inorder,postorder,postleft+root_in_pos-inleft,postright-1,root_in_pos+1,inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            hash[inorder[i]]=i;
        return myBuildTree(inorder,postorder,0,n-1,0,n-1);
    }
};
// @lc code=end

