/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                return check(s,l,r-1)||check(s,l+1,r);
            }
            l++,r--;
        }
        return true;
    }
    bool check(const string& s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
};
// @lc code=end

