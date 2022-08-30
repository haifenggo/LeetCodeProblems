/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        }
        );
        int edge=points[0][1];
        int ret=1;
        for(int i=1;i<n;i++){
            if(points[i][0]<=edge){
                // edge=min(edge,points[i][1]);
            }else{
                ret++;
                edge=points[i][1];
            }
        }
        return ret;
    }
};
// @lc code=end

