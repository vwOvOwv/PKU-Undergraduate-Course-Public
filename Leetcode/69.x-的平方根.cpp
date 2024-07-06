/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {//二分查找
public:
    int mySqrt(int x) {
        int L=1,R=x;
        int ans;
        while(L<=R){
            int mid=L+(R-L)/2;
            if(mid<x/mid){//mid*mid int溢出
                ans=mid;
                L=mid+1;
            }
            else if(mid>x/mid){
                R=mid-1;
            }
            else{
                ans=mid;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

