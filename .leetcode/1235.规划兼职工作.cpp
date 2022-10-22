/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),
        [](vector<int>&j1,vector<int>&j2){
            return j1[1]<j2[1];
        });
        vector<int>f(n+1);
        for(int i=1;i<=n;i++){
            int k=upper_bound(jobs.begin(),jobs.begin()+i-1,jobs[i-1][0],
            [&](int x,vector<int>&j){
                return x<j[1];
            })-jobs.begin();
            f[i]=max(f[i-1],jobs[i-1][2]+f[k]);
        }
        return f[n];
    }
};
// @lc code=end

