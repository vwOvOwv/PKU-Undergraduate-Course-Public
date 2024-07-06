/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size(),first=0;
        digits[len-1]++;
        for(int i=len-1;i>=1;i--){
            if(digits[i]>=10){
                digits[i]-=10;
                digits[i-1]++;
            }
        }
        if(digits[0]>=10){
            digits[0]-=10;
            first++;
            digits.insert(digits.begin(),first);
        }
        return digits;
    }
};
// @lc code=end

