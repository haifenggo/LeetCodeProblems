/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        backtracking(ans,nums,0);
        return ans;
    }
    void backtracking(vector<vector<int>>&ans,vector<int>& nums,int size){
        if(size==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=size;i<nums.size();i++){
            swap(nums[i],nums[size]);
            backtracking(ans,nums,size+1);
            swap(nums[i],nums[size]);
        }
        
    }
};
// @lc code=end

