/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mp;
    vector<string>ans;
    void dfs(const string& s){
        // while(!mp.count(s)&&mp[s].)
        while(!mp[s].empty()){
            string nxt=mp[s].top();
            mp[s].pop();
            dfs(nxt);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& a:tickets){
            mp[a[0]].push(a[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

