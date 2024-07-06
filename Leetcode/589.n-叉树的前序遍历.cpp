/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int>ans;
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
    void dfs(Node*root){
        if(root){
            ans.push_back(root->val);
            int n=root->children.size();
            for(int i=0;i<n;i++)
                dfs(root->children[i]);
        }
    }
};
// @lc code=end

