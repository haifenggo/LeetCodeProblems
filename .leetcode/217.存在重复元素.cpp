/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &a:nums){
            if(mp[a]>0){return true;}
            else{
                mp[a]++;
            }
        }
        return false;
    }
};
// @lc code=end

