/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if(!x)
            return 0;
        long long int num=0;
        bool positive;
        if(x>0)
            positive=true;
        else{
            if(x==INT_MIN)
                return 0;
            x=-x;
            positive=false;
        }
        while(x){
            num=num*10+x%10;
            x/=10;
        }
        if(!positive)
            num=-num;
        if(num>=INT_MAX||num<=INT_MIN)
            return 0;
        return num;
    }
};
// @lc code=end

