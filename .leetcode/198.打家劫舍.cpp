/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        int a=nums[0],b=max(nums[0],nums[1]),ans=0;
        for(int i=2;i<n;i++){
            a=a+nums[i];
            if(a>b){
                ans=a;
                swap(a,b);
            }else{
                ans=b;
                a=b;
            }
        }
        return ans;
    }
};
// @lc code=end

