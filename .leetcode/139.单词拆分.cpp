/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>f(n+1,false);
        f[0]=true;
        for(int i=1;i<=n;i++){
            for(string& cur:wordDict){
                if(i>=cur.size()&&s.substr(i-cur.size(),cur.size())==cur){
                    f[i]=f[i]||f[i-cur.size()];
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

