/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(j-i<=k&&nums[i]!=nums[j])
                j++;
            else if(j-i<=k&&nums[i]==nums[j])
                return true;
            else if(j-i>k)
                i++;
        }
    }
};
// @lc code=end

