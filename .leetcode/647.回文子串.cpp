/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=check(i,i,s.size(),s);
            ans+=check(i,i+1,s.size(),s);
        }
        return ans;
    }
    int check(int l,int r,int n,string& s){
        int ans=0;
        while(l>=0&&r<n&&s[l]==s[r]){
            ans++;
            l--;r++;
        }
        return ans;
    }
};
// @lc code=end

