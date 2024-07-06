/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,tmp;
        vector<int>sorted;//做不到O(1)空间就开大一点
        while(j<n&&i<m){
            if(nums1[i]>=nums2[j]){
                sorted.push_back(nums2[j]);
                j++;
            }
            else{
                sorted.push_back(nums1[i]);
                i++;
            }
        }
        if(i<m){
            for(;i<m;i++)
                sorted.push_back(nums1[i]);
        }
        if(j<n){
            for(;j<n;j++)
                sorted.push_back(nums2[j]);
        }
        nums1=sorted;
    }
};
// @lc code=end

