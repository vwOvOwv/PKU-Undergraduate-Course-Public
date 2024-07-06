/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxi=-1;
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        dfs(root,1);
        return maxi;
    }
    void dfs(Node*root,int depth){
        if(root){
            int n=root->children.size();
            if(n==0)
                maxi=max(maxi,depth);
            for(int i=0;i<n;i++)
                dfs(root->children[i],depth+1);
        }
    }
};
// @lc code=end

