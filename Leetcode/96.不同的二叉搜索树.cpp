/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    /*
    int numTrees(int n) {//动态规划，数学推导（Catalan数）
        int dp[21]={0};
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    */
   int numTrees(int n){//Catalan数递推
        long long int ans=1;
        for(int i=2;i<=n;i++){
            ans=2*ans*(2*i-1)/(i+1);
        }
        return ans;
   }
};
// @lc code=end

