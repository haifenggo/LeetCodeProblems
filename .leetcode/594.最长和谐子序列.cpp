/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int& a:nums){
            mp[a]++;
        }
        for(auto [k,v]:mp){
            if(mp.count(k+1)){
                ans=max(ans,v+mp[k+1]);
            }
        }
        return ans;
    }
};
// @lc code=end

