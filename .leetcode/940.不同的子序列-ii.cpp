/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;
        vector<int>f(n,1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(last[j]!=-1){
                    f[i]=(f[i]+f[last[j]])%mod;
                }
            }
            last[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(last[i]!=-1) ans=(ans+f[last[i]])%mod;
        }
        return ans;
    }
};
// @lc code=end

