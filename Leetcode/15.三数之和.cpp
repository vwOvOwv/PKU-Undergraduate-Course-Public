/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//排序+三变量->双变量+双指针
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=n-1;
        
        for(int i=0;i<n;i++){
            target=-nums[i];
        }
        loop:;
        return ans;
    }
};
// @lc code=end

