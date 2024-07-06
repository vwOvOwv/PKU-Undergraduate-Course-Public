/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int len=operations.size();
        for(int i=0;i<len;i++){
            if(operations[i]=="+"){
                int tmp1=st.top();
                st.pop();
                int tmp2=st.top();
                st.push(tmp1);
                st.push(tmp1+tmp2);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int tmp1=st.top();
                st.push(2*tmp1);
            }
            else{
                st.push(atoi(operations[i].c_str()));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

