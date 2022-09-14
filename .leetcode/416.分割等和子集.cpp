/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=accumulate(nums.begin(),nums.end(),0);
        if(n%2==1){return false;}
        n=n/2;
        vector<bool>f(n+1);
        f[0]=true;
        for(int i=0;i<nums.size();i++){
            for(int j=n;j>=0;j--){
                if(nums[i]>j){
                    
                }else{
                    f[j]=f[j]||f[j-nums[i]];
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

