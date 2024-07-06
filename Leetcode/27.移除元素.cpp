/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int n=nums.size();//O(n^2)暴力破解
        // if(n==0)return 0;
        // int cnt=0;//cnt是当前被删除元素的个数
        // for(int i=0;i<n-cnt;i++){//i的长度应小于当前数组的真实长度，避免重复计算数组尾部的数字
        //     if(nums[i]==val){
        //         for(int j=i;j<n-1;j++)//平移删除
        //             nums[j]=nums[j+1];
        //         i--;//i要退一位
        //         cnt++;
        //     }
        // }
        // return n-cnt;
        
        //快慢指针
        //快指针：寻找新数组的元素
        //慢指针：确定新数组最后一个元素后面的位置
        int slow=0,fast=0;
        for(fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

