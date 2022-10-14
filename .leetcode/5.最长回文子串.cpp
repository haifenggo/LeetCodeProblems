/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    int mx=0;
    string longestPalindrome(string s) {
        int n=s.size();
        int index=0;
        for(int i=0;i<n;i++){
            int cur=f(s,i,i);
            if(cur>=0)index=cur;
            cur=f(s,i-1,i);
            if(cur>=0)index=cur;
        }
        return s.substr(index,mx);

    }
    int f(string& s,int l,int r){
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            l--;r++;
        }
        l++,r--;
        if(r-l+1>mx){
            mx=r-l+1;
            return l;
        }
        return -1;
    }
};
// @lc code=end

