/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<double,int>mp;
        int ans=0,y=0;
        for(int i=0;i<points.size();i++){
            y=0;
            int pi=points[i][0],pj=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int pii=points[j][0],pjj=points[j][1];
                if(pj==pjj){y++;}
                else{
                    mp[(double)(pi-pii)/(double)(pj-pjj)]++;
                }
            }
            ans=max(ans,y);
            for(auto& a:mp){
                ans=max(ans,a.second);
            }
            mp.clear();
        }
        return ans+1;
    }
};
// @lc code=end

