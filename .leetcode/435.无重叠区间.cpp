/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){return 0;}
        sort(intervals.begin(),intervals.end(),
        [](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        vector<int>f(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(intervals[i][0]>=intervals[j][1]){
                    f[i]=max(f[i],f[j]+1);
                }
            }
        }
        return n-*max_element(f.begin(),f.end());
    }
};
// @lc code=end

