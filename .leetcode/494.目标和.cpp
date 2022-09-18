/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int dif=sum-target;
        if(dif<0||dif%2!=0){return 0;}
        sum=dif/2;
        vector<vector<int>>f(n+1,vector<int>(sum+1,0));
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j<nums[i-1]){
                    f[i][j]=f[i-1][j];
                }else{
                    f[i][j]=f[i-1][j]+f[i-1][j-nums[i-1]];
                }
            }
        }
        return f[n][sum];
    }
};
// @lc code=end

