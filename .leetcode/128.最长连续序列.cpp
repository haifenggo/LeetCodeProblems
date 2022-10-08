/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp;
        int ans=0;
        for(int& a:nums){
            mp.insert(a);
        }
        while(!mp.empty()){
            int cur=*(mp.begin());
            mp.erase(cur);
            int nxt=cur+1,pre=cur-1;
            while(mp.count(nxt)){
                mp.erase(nxt++);
            }
            while(mp.count(pre)){
                mp.erase(pre--);
            }
            ans=max(ans,nxt-pre-1);
        }
        return ans;
    }
};
// @lc code=end

