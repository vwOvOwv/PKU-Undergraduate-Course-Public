/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {//高精度乘法
        if(num1=="0"||num2=="0")
            return "0";
        int l1=num1.size(),l2=num2.size();
        string ans="0";
        string tmp;
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                tmp.clear();
                // tmp.push_back((num1[i]-'0')*(num2[j]-'0')+'0');//char字符越界！！！
                tmp.push_back((num1[i]-'0')*(num2[j]-'0'));
                int cnt=0;
                while(tmp[0]>=10){
                    tmp[0]-=10;
                    cnt++;
                }
                tmp[0]+='0';
                if(cnt>0){
                    char t=tmp[0];
                    tmp[0]='0'+cnt;
                    tmp.push_back(t);
                }
                for(int k=0;k<l1+l2-(i+j)-2;k++){
                    tmp.push_back('0');
                }
                if(ans.size()>=tmp.size())
                    ans=add(ans,tmp);
                else
                    ans=add(tmp,ans);
            }
        }
        return ans;
    }
    string add(string num1,string num2){
        int l1=num1.size(),l2=num2.size();
        int i=l2-1,j=l1-1;//想清楚！！！
        while(i>=0){
            num1[j]=num1[j]+num2[i]-'0';
            i--;j--;
        }
        i=l1-1;
        while(i>=0){
            if(num1[i]-'0'>=10){
                num1[i]-=10;
                if(i){
                    num1[i-1]++;
                }
                else{
                    string tmp=num1;
                    num1="1";
                    num1+=tmp;
                    break;
                }
            }
            i--;
        }
        return num1;
    }
};
// @lc code=end

