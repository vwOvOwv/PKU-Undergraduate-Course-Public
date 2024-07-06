/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        bool flagi,flagj;
        char letters[10]={'a','e','i','o','u','A','E','I','O','U'};
        while(i<=j){
            flagi=false,flagj=false;
            for(int k=0;k<10;k++){
                if(s[i]==letters[k])
                    flagi=true;
                if(s[j]==letters[k])
                    flagj=true;
            }
            if(flagi&&flagj){
                char tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                i++,j--;
            }
            else if(flagi&&!flagj){
                j--;
            }
            else if(!flagi&&flagj){
                i++;
            }
            else{
                i++,j--;
            }
        }
        return s;
    }
};
// @lc code=end

