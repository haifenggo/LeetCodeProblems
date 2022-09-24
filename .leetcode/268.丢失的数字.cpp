/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ans^=i;
            ans^=nums[i];
        }
        return ans^n;

    }
};
// @lc code=end

