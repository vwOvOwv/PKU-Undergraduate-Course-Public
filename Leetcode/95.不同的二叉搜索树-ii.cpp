/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
class Solution {//递归分治
/*
将区间分为三部分，枚举根结点的值i，则left～i必然在左子树上，而right~i必然在
右子树上；将所有可能的左子树与所有可能的右子树拼接起来即得到所有可能的二叉搜索树；
而左、右子树也是二叉搜索树，因此可以用相同方法得到所有可能的左子树与右子树
*/
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans;
        ans=generate(1,n);
        return ans;
    }
    vector<TreeNode*>generate(int _left, int _right){
        vector<TreeNode*>ans;
        if(_left>_right){//终止条件
            ans.push_back(nullptr);//注意要加入空指针
            return ans;
        }
        for(int i=_left;i<=_right;i++){//枚举根结点
            vector<TreeNode*>leftTree=generate(_left,i-1);//递归寻找所有可能的左子树
            vector<TreeNode*>rightTree=generate(i+1,_right);//递归寻找所有可能的右子树
            for(auto&l:leftTree){//组合起来
                for(auto&r:rightTree){
                    TreeNode*root=new TreeNode(i);//注意每次根结点都要new一个新的
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

