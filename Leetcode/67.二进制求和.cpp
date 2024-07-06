/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {//高精度加法
        if(a.size()<b.size())
            swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<b.size();i++){
            a[i]=a[i]+b[i]-'0';
        }
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>='2'){
                a[i]-=2;
                a[i+1]++;
            }
        }
        if(a[a.size()-1]>='2'){
            a[a.size()-1]-=2;
            a.push_back('1');
        }
        reverse(a.begin(),a.end());
        return a;
    }
};
// @lc code=end

