/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
            else {
                switch (s[i])
                {
                case ')':
                    if(!st.empty()&&st.top()=='(')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if(!st.empty()&&st.top()=='[')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if(!st.empty()&&st.top()=='{')
                        st.pop();
                    else
                        return false;
                    break;
                }
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

