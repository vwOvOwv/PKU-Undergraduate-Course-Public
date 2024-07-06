/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>tmp=nums;
        sort(tmp.begin(),tmp.end());
        vector<int>ans;
        int k=nums.size()-1;
        int i=0,j=k;
        while(i<j){
            if(tmp[i]+tmp[j]<target)
                i++;
            else if(tmp[i]+tmp[j]>target)
                j--;
            else{
                int ii;
                for(ii=0;ii<=k;ii++){
                    if(nums[ii]==tmp[i]||nums[ii]==tmp[j])
                        ans.push_back(ii);
                }
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

