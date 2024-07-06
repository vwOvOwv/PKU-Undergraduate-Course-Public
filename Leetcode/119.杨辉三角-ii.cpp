/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {//递推
        vector<int>prev(2,1),cur;
        if(rowIndex==0){
            cur.push_back(1);
            return cur;
        }
        if(rowIndex==1){
            cur.push_back(1);
            cur.push_back(1);
            return cur;
        }
        for(int i=1;i<rowIndex;i++){
            cur.resize(prev.size()+1);
            for(int j=0;j<cur.size();j++){
                if(j==0||j==cur.size()-1)
                    cur[j]=1;
                else
                    cur[j]=prev[j-1]+prev[j];
            }
            prev=cur;
        }
        return cur;
    }
};
// @lc code=end

