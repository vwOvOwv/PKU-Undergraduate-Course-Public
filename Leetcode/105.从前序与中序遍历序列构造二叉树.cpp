/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
class Solution {//分治
/*
中序序列中每一个结点左（右）侧的是其左（右）子树上的结点
*/
public:
    unordered_map<int,int>hash;//哈希表存储每一个根结点在中序遍历序列中的位置
    TreeNode*myBuildTree(vector<int> preorder,vector<int>inorder,int preleft,int preright,int inleft,int inright){
        //myBuildTree 根据一段对应的前序与中序遍历序列建树
        if(preleft>preright)//边界条件
            return nullptr;
        int root_in_pos=hash[preorder[preleft]];
        TreeNode*root=new TreeNode(preorder[preleft]);
        root->left=myBuildTree(preorder,inorder,preleft+1,preleft+root_in_pos-inleft,inleft,root_in_pos-1);//计算得出前序序列中左子树所在区域
        root->right=myBuildTree(preorder,inorder,preleft+root_in_pos-inleft+1,preright,root_in_pos+1,inright);//计算得出前序序列中右子树所在区域
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++)
            hash[inorder[i]]=i;
        return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
};
// @lc code=end

