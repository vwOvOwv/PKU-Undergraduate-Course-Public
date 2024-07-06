/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {//双指针，谁小移谁，证明可以用反证法+分类讨论
        int l=0,r=height.size()-1,ans=0;
        while(l<=r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
// @lc code=end

