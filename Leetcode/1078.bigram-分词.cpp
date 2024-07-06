/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stack<string>st;
        vector<string>ans;
        string word;
        for(int i=0;i<text.size();i++){
            if(text[i]!=' '){
                word.push_back(text[i]);
            }
            else{
                if(!st.empty()&&st.top()==second){
                    st.pop();
                    if(!st.empty()&&st.top()==first)
                        ans.push_back(word);
                    st.push(second);
                }
                st.push(word);
                word.clear();
            }
        }
        if(!st.empty()&&st.top()==second){
            st.pop();
            if(!st.empty()&&st.top()==first)
                ans.push_back(word);
            st.push(second);           
        }
        return ans;
    }
};
// @lc code=end

