/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {//哈希+dfs
        if(digits.size()==0)
            return vector<string>();
        unordered_map<char,string >hashtable;
        char letter='a';
        for(char i='2';i<='9';i++){
            // hashtable.insert(i);
            for(int j=0;j<3;j++){
                hashtable[i].push_back(letter);
                ++letter;
            }
            if(i=='7'||i=='9'){
                hashtable[i].push_back(letter);
                ++letter;
            }
        }
        int n=digits.size();
        vector<string>ans;
        string tmp;
        dfs(ans,digits,hashtable,0,tmp);
        return ans;
    }
    void dfs(vector<string>&ans,string digits,unordered_map<char,string>hashtable,int k,string tmp){
        if(k==digits.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<hashtable[digits[k]].size();i++){
            tmp.push_back(hashtable[digits[k]][i]);
            dfs(ans,digits,hashtable,k+1,tmp);
            tmp.pop_back();
            //回溯
        }
    }
};
// @lc code=end

