/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {//二分查找
        int L=0,R=nums.size()-1;
        int mid;
        while(L<=R){
            mid=L+(R-L)/2;
            if(nums[mid]<target)
                L=mid+1;
            else if(nums[mid]>target)
                R=mid-1;
            else
                return mid;
        }
        return L;
    }
};
// @lc code=end

