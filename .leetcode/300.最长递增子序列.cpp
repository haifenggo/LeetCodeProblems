/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>f;
        f.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(f.back()<nums[i]){
                f.push_back(nums[i]);
            }else{
                auto it=lower_bound(f.begin(),f.end(),nums[i]);
                *it=nums[i];
            }
        }
        return f.size();

        // vector<int>f(n+1,1);
        // int ans=1;
        // for(int i=2;i<=n;i++){
        //     for(int j=1;j<i;j++){
        //         if(nums[j-1]<nums[i-1]){
        //             f[i]=max(f[i],f[j]+1);
        //         }
        //     }
        //     ans=max(ans,f[i]);
        // }
        // return ans;
    }
};
// @lc code=end

