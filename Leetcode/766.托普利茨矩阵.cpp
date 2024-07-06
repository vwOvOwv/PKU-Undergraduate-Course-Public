/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int h=matrix.size();
        int w=matrix[0].size();
        for(int i=0;i<h;i++){
            int target=matrix[i][0];
            for(int j=1;j<h-i;j++){
                if(j<w&&matrix[i+j][j]!=target)
                    return false;
            }
        }
        for(int i=1;i<w;i++){
            int target=matrix[0][i];
            for(int j=1;j<w-i;j++){
                if(j<h&&matrix[j][i+j]!=target)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

