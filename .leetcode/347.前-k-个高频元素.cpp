/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>counts;
        int mx=0;
        for(auto& a:nums){
            mx=max(mx,++counts[a]);
        }
        vector<vector<int>>bucket(mx+1);
        for(auto&a:counts){
            bucket[a.second].push_back(a.first);
        }
        vector<int>ans;
        for(int i=mx;i>=0&&ans.size()<k;i--){
            for(auto&a:bucket[i]){
                ans.push_back(a);
                if(ans.size()==k)break;
            }
        }
        return ans;
    }
};
// @lc code=end

