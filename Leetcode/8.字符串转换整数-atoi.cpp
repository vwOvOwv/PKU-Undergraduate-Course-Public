/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long long int ans=0;
        string rec;
        bool positive=true;
        int n=s.length();
        for(int i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]=='.')
                return 0;
            if(s[i]=='+'){
                int j=i+1;
                while(j<n&&s[j]>='0'&&s[j]<='9')
                    j++;
                rec=s.substr(i+1,j-i-1);
                break;
            }
            if(s[i]=='-'){
                positive=false;
                int j=i+1;
                while(j<n&&s[j]>='0'&&s[j]<='9')
                    j++;
                rec=s.substr(i+1,j-i-1);
                break;
            }
            if(s[i]>='0'&&s[i]<='9'){
                int j=i;
                while(j<n&&s[j]>='0'&&s[j]<='9')
                    j++;
                rec=s.substr(i,j-i);
                break;
            }
        }
        n=rec.length();
        for(int i=0;i<n;i++){
            ans=ans*10+rec[i]-'0';
            if(positive&&ans>INT_MAX)
                return INT_MAX;
            if(!positive&&-ans<INT_MIN)
                return INT_MIN;
        }
        if(!positive)
            ans=-ans;
        return ans;
    }
};
// @lc code=end

