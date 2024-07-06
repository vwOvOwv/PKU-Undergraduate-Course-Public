/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(auto ch:s){
            if(ch>='A'&&ch<='Z'){
                ch=ch-'A'+'a';
                res.push_back(ch);
            }
            else if(ch>='a'&&ch<='z')
                res.push_back(ch);
            else if(ch>='0'&&ch<='9')
                res.push_back(ch);
        }
        int n=res.size();
        int i=0,j=n-1;
        while(i<=j){
            if(res[i]!=res[j])
                return false;
            i++;j--;
        }
        return true;
    }
};
// @lc code=end

