/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {//kmp算法
        int nlen=needle.size(),hlen=haystack.size();
        if(nlen>hlen)
            return -1;
        vector<int>next(nlen,0);
        next[0]=-1;
        int j=0;
        int k=-1;
        while(j<nlen-1){
            //int k=next[j]; 优化写法这里就会使得k是优化后的next[j];
            while(k>=0&&needle[j]!=needle[k])
                k=next[k];
            k++;
            j++;
            next[j]=k;
            if(needle[j]==needle[k])
                next[j]=next[k];
        }
        int i=0;j=0;
        while(i<hlen&&j<nlen){
            if(j==-1||haystack[i]==needle[j])
                i++,j++;
            else
                j=next[j];
        }
        if(j>=nlen)
            return i-nlen;
        else
            return -1;
    }
};
// @lc code=end

