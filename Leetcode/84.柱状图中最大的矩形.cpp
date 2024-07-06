/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {//单调栈
        stack<int>st;
        int n=heights.size();
        vector<int>left(n),right(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<=heights[st.top()])
                st.pop();
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[i]<=heights[st.top()])
                st.pop();
            right[i]=st.empty()?n:st.top();//注意n和-1的取法
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};
// @lc code=end

