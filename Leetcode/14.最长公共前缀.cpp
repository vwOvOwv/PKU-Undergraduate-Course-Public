/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)//横向扫描，纵向扫描也可且更好理解
    {
        string now=strs[0];//now是当前最长公共前缀，最长公共前缀的长度是单调递减的（只会越来越短）
        for (auto str : strs)
        {
            int len = now.size();
            for (int i = 0; i < len; i++)
            {
                if(i==str.size())//注意如果str已经结束了而now还未结束则说明当前最长公共前缀就是str
                    now=str;
                if (str[i] != now[i]){
                    now=str.substr(0,i);
                    break;
                }
            }
            if(now.empty())
                return now;
        }
        return now;
    }
};
// @lc code=end
