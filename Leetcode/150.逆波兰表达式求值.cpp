/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long int>st;
        for(int i=0;i<tokens.size();i++){
            string s=tokens[i];
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                long int num1=st.top();st.pop();
                long int num2=st.top();st.pop();
                if(s=="+")
                    st.push(num1+num2);
                if(s=="-")
                    st.push(num2-num1);
                if(s=="*")
                    st.push(num1*num2);
                if(s=="/")
                    st.push(num2/num1);
            }
            else{
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
// @lc code=end

