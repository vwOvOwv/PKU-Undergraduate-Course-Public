/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int p=0,q=0,n=nums.size();
        if(!n)
            return ans;
        while(q<n-1){
            if(nums[q+1]-1==nums[q])
                q++;
            else{
                string tmp=itos(nums[p]);
                if(q!=p){
                    tmp+="->";
                    tmp+=itos(nums[q]);
                }
                ans.push_back(tmp);
                q++;
                p=q;
            }
        }
        string tmp=itos(nums[p]);
        if(q!=p){
            tmp+="->";
            tmp+=itos(nums[q]);
        }
        ans.push_back(tmp);
        return ans;
    }
    string itos(long int num){//-2^31把负号去掉int就溢出了！！！
        if(!num){
            return "0";
        }
        string ans;
        if(num<0){
            ans.push_back('-');
            num=-num;
        }
        string tmp;
        while(num){
            int t=num%10;
            num/=10;
            tmp.push_back(t+'0');
        }
        int n=tmp.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(tmp[i]);
        }
        return ans;
    }
};
// @lc code=end

