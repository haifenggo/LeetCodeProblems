/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        int pre=0;
        mp[0]=1;
        for(int i=1;i<=nums.size();i++){
            pre=pre+nums[i-1];
            ans+=mp[pre-k];
            mp[pre]++;
        }
        return ans;
    }
};
// @lc code=end

