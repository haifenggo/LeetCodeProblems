/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>first,last;
        int n=nums[0],mx=0,i=0;
        int ans=9999999;
        for(int& a:nums){
            mp[a]++;
            if(mp[a]>mx){
                mx=mp[a];
            }
            if(first[a]==0){
                first[a]=i+1;
            }
            last[a]=i+1;
            i++;
        }
        for(auto& a:mp){
            if(a.second==mx){
                ans=min(ans,last[a.first]-first[a.first]+1);
            }
        }
        return ans;
    }
};
// @lc code=end

