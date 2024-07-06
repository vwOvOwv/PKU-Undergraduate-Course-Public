/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {//要求是单射函数
        int len=s.size();
        unordered_map<char,char>hashtable;
        unordered_map<char,char>reverse;
        for(int i=0;i<len;i++){
            if(hashtable.find(s[i])!=hashtable.end()){
                if(hashtable[s[i]]!=t[i])
                    return false;
            }
            else{
                hashtable[s[i]]=t[i];
            }
            if(reverse.find(t[i])!=reverse.end()){
                if(reverse[t[i]]!=s[i])
                    return false;
            }
            else{
                reverse[t[i]]=s[i];
            }
        }
        return true;
    }
};
// @lc code=end

