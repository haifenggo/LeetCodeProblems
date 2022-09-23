/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<words.size();i++){
            int n=words[i].size();
            int m=0;
            for(const char& ch:words[i]){
                m|=1<<(ch-'a');
            }
            mp[m]=max(mp[m],n);
            for(auto [a,b]:mp){
                if(!(m&a)){
                    ans=max(ans,n*b);
                }
            }
            
        }
        return ans;
    }
};
// @lc code=end

