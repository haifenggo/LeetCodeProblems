/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        if(n!=t.size())return false;
        unordered_map<char,bool>mp;
        unordered_map<char,char>f;
        unordered_map<char,bool>ft;
        for(int i=0;i<n;i++){
            if(mp[s[i]]){
                if(f[s[i]]!=t[i])return false;
            }else{
                if(ft[t[i]])return false;
                mp[s[i]]=true;
                f[s[i]]=t[i];
                ft[t[i]]=true;
            }
        }
        return true;
    }
};
// @lc code=end

