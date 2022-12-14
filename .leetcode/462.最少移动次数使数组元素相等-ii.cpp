/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int x=nums[nums.size()/2];
        for(int i=0;i<nums.size();i++){
            ans+=abs(x-nums[i]);
        }
        return ans;
    }
};
// @lc code=end

