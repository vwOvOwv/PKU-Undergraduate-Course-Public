/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //hash
        /*unordered_set<int>rec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!rec.count(nums[i])){
                rec.insert(nums[i]);
            }
            else
                rec.erase(nums[i]);
        }
        return *rec.begin();*/
        //位运算
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
            res^=nums[i];
        return res;
    }
};
// @lc code=end

