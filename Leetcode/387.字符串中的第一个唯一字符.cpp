/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int ans=-1;
        int n=s.size();
        unordered_map<char,int>rec;
        for(int i=0;i<n;i++)
            rec[s[i]]++;
        for(int i=0;i<n;i++){
            if(rec[s[i]]==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

