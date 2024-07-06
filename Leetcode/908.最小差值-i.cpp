/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {//数学题
        int maxi=*(max_element(nums.begin(),nums.end())),mini=*(min_element(nums.begin(),nums.end()));
        if(maxi-mini<=2*k)
            return 0;
        else
            return maxi-mini-2*k;
    }
};
// @lc code=end

