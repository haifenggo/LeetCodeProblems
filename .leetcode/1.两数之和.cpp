/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            auto pos=mp.find(target-n);
            if(pos==mp.end()){
                mp[n]=i;
            }else{
                ans.push_back(pos->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

