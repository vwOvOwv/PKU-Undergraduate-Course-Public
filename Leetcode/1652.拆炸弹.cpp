/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0){
            return ans;
        }
        if(k>0){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<=i+k;j++){
                    ans[i]+=code[j%n];
                }
            }
        }
        if(k<0){
            for(int i=0;i<n;i++){
                for(int j=i-1;j>=i+k;j--){
                    int tmp=j;
                    if(tmp<0){
                        while(tmp<0){
                            tmp+=n;
                        }
                    }
                    ans[i]+=code[tmp];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

