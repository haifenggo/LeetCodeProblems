/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=n+1;
        vector<long>s(n+1,0);
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+nums[i];
        }
        deque<int>q;
        q.push_back(0);
        for(int i=0;i<n;i++){
            while(!q.empty()&&s[i+1]-s[q.front()]>=k){
                ans=min(ans,i+1-q.front());
                q.pop_front();
            }
            while(!q.empty()&&s[q.back()]>s[i+1]){
                q.pop_back();
            }
            q.push_back(i+1);
        }

        return ans==n+1?-1:ans;
    }
};

// @lc code=end

