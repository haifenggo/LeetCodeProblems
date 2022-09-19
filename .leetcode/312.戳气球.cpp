/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    vector<int>val;
    vector<vector<int>>f;
    int solve(int l,int r){
        if(l>=r-1)return 0;
        if(f[l][r]!=-1){
            return f[l][r];
        }
        for(int i=l+1;i<r;i++){
            int s=val[l]*val[i]*val[r];
            s+=solve(l,i)+solve(i,r);
            f[l][r]=max(f[l][r],s);
        }
        return f[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        val.resize(n+2);
        for(int i=0;i<n;i++){
            val[i+1]=nums[i];
        }
        val[0]=val[n+1]=1;
        f.resize(n+2,vector<int>(n+2,-1));
        return solve(0,n+1);
    }
};
// @lc code=end

