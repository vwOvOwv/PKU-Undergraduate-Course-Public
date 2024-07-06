/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int i=0,j=0,l1=ransomNote.size(),l2=magazine.size();
        while(i<l1&&j<l2){
            if(ransomNote[i]<magazine[j])
                return false;
            else if(ransomNote[i]>magazine[j])
                j++;
            else
                i++,j++;
        }
        if(i==l1)
            return true;
        return false;
    }
};
// @lc code=end

