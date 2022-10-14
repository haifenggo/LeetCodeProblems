/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        int mx=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto [ch,n]:mp){
            if(n%2==1){
                ans+=n-1;
                mx=1;
            }else{
                ans+=n;
            }
        }
        return mx?1+ans:ans;
    }
};
// @lc code=end

