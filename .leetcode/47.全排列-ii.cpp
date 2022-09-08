/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<bool>vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>one;
        vector<vector<int>>ans;
        vis.resize(nums.size());
        sort(nums.begin(),nums.end());
        backtracking(0,nums,one,ans);
        return ans;
    }
    void backtracking(int index,vector<int>& nums,vector<int>&one,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(one);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]||(i>0&&nums[i-1]==nums[i]&&!vis[i-1])){
                continue;
            }
            vis[i]=1;
            one.push_back(nums[i]);
            backtracking(index+1,nums,one,ans);
            one.pop_back();
            vis[i]=0;
        }
    }
};
// @lc code=end

