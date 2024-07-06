/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>rec;
        for(auto num:nums){
            if(rec.count(num))
                return true;
            else
                rec.insert(num);
        }
        return false;
    }
};
// @lc code=end

