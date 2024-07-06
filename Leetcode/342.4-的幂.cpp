/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        /*
        if(n==1)
            return true;
        if(n&1||n<=0)//n为奇数或n为非正数
            return false;
        if((n&(n-1))==0){//二进制位必然只有一个1
            for(int i=0;i<32;i++){
                if((n&(1<<i))&&i%2==0)//1在奇数位上（最低位为第零位）
                    return true;
            }
        }
        return false;
        */
       //构造mask
       //4的幂的二进制数必然只有一个1且这个1在偶数位上
       //1个16进制位是4个二进制位
       return n>0&&!(n&(n-1))&&!(n&0xaaaaaaaa);
    }
};
// @lc code=end

