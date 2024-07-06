/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        char tmp;
        int i;
        for(i=0;i<s.size()-1;i++){
            if(s[i]=='I'&&s[i+1]=='V'){
                ans+=4;
                i++;//跳一位
            }
            else if(s[i]=='I'&&s[i+1]=='X'){
                ans+=9;
                i++;
            }
            else if(s[i]=='X'&&s[i+1]=='L'){
                ans+=40;
                i++;
            }
            else if(s[i]=='X'&&s[i+1]=='C'){
                ans+=90;
                i++;
            }
            else if(s[i]=='C'&&s[i+1]=='D'){
                ans+=400;
                i++;
            }
            else if(s[i]=='C'&&s[i+1]=='M'){
                ans+=900;
                i++;
            }
            else{
                switch (s[i])
                {
                    case 'I':ans+=1;break;
                    case 'V':ans+=5;break;
                    case 'X':ans+=10;break;
                    case 'L':ans+=50;break;
                    case 'C':ans+=100;break;
                    case 'D':ans+=500;break;
                    case 'M':ans+=1000;break;
                }
            }
        }
        if(i==s.size()-1){//最后一位要特判，如果最后一位和前一位在一起加了那i=s.size()-1+1+1
             switch (s[i])
                {
                    case 'I':ans+=1;break;
                    case 'V':ans+=5;break;
                    case 'X':ans+=10;break;
                    case 'L':ans+=50;break;
                    case 'C':ans+=100;break;
                    case 'D':ans+=500;break;
                    case 'M':ans+=1000;break;
                }
        }
        return ans;
    }
};
// @lc code=end

