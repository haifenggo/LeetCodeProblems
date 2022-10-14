/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMP(haystack,needle);

    }
    int KMP(string& haystack, string& needle){
        int n=needle.size();
        vector<int>next(n,-1);
        calnext(needle,next);
        int m=haystack.size();
        int p=-1,k=0;
        for(int i=0;i<m;i++){
            while(p>-1&&needle[p+1]!=haystack[i]){
                p=next[p];
            }
            if(needle[p+1]==haystack[i]){
                p++;
            }
            if(p==n-1){
                return i-n+1;
            }
        }
        return -1;
    }
    void calnext(string& t,vector<int>& nxt){
        int siz=t.size();
        int p=-1;
        for(int i=1;i<siz;i++){
            while(p>-1&&t[p+1]!=t[i]){
                p=nxt[p];
            }
            if(t[p+1]==t[i]){
                p++;
            }
            nxt[i]=p;
        }
    }
};
// @lc code=end

