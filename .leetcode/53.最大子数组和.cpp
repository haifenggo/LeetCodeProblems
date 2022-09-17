/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int cur=0,ans=-100000;
        for(int i=0;i<n;i++){
            cur=max(cur+nums[i],nums[i]);
            ans=max(cur,ans);
        }
        return ans;

    }
};
// @lc code=end

