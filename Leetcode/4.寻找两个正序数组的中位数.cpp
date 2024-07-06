/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<int>num;
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }
            else{
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            num.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            num.push_back(nums2[j]);
            j++;
        }
        int len=m+n;
        if(len%2){
            
        }
    }
};
// @lc code=end

