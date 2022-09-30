/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp=[](pair<int,int>a,pair<int,int>b)->bool{return a.second<b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)>q(cmp);
        vector<int>bian;
        for(auto& b:buildings){
            bian.push_back(b[0]);
            bian.push_back(b[1]);
        }
        sort(bian.begin(),bian.end());
        vector<vector<int>>ans;
        int i=0,mx=0;
        int n=buildings.size();
        for(auto& b:bian){
            while(i<n&&buildings[i][0]<=b){
                q.push({buildings[i][1],buildings[i][2]});
                i++;
            }
            while(!q.empty()&&q.top().first<=b){
                q.pop();
            }
            mx=q.empty()?0:q.top().second;
            if(ans.empty()||mx!=ans.back()[1]){
                ans.push_back({b,mx});
            }
        }
        return ans;
    }
};
// @lc code=end

