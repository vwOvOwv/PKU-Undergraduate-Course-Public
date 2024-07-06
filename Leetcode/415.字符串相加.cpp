/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        if(l1<l2){
            swap(l1,l2);
            swap(num1,num2);
        }
        int i=l1-1,j=l2-1;
        while(j>=0){
            num1[i]=num1[i]+num2[j]-'0';
            i--,j--;
        }
        i=l1-1;
        while(i>=0){
            if(num1[i]-'0'>=10){
                num1[i]-=10;
                if(i)
                    num1[i-1]++;
                else{
                    string tmp=num1;
                    num1="1";
                    num1+=tmp;
                }
            }
            i--;
        }
        return num1;
    }
};
// @lc code=end

