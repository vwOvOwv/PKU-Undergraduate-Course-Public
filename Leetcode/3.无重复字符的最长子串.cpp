
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {//滑动窗口+双指针
        unordered_set<char>rec;
        int len=s.size();
        int ans=0,r=0;
        for(int l=0;l<len;l++){
            if(l!=0)
                rec.erase(s[l-1]);
            while(r<len){
                if(!rec.count(s[r])){
                    rec.insert(s[r]);
                    r++;
                }
                else{
                    //ans=max(ans,r-l);不能这样写！！！"au"一路跑到结尾了到不了这条语句！！！
                    break;
                }
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};
// @lc code=end

