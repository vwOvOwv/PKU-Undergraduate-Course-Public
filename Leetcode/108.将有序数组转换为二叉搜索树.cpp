/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return generate(0,n-1,nums);
    }
    TreeNode*generate(int start,int end,vector<int>num){
        if(start>end)
            return nullptr;
        int mid=(start+end)/2;
        TreeNode*root=new TreeNode(num[mid]);
        root->left=generate(start,mid-1,num);
        root->right=generate(mid+1,end,num);
        return root;
    }
};
// @lc code=end

