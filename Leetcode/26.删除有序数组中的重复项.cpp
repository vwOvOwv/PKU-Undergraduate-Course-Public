/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {//快慢指针
        int n=nums.size();
        if(n<2)
            return n;
        int p=0,q=1;
        while(q<n){
            if(nums[p]!=nums[q]){
                p++;
                nums[p]=nums[q];
            }
            q++;
        }
        return p+1;
    }
};
// @lc code=end

