/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {//n&(n-1)消除n末尾的1
        int cnt=0;
        /*for(int i=0;i<32;i++){
            if(((1<<i)&n)!=0)
                cnt++;
        }*/
        while(n){
            cnt++;
            n&=(n-1);
        }
        return cnt;
    }
};
// @lc code=end

