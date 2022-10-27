/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>in(n);
        vector<vector<int>>g(n);
        for(int i=0;i<p.size();i++){
            g[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!in[i])q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int& v:g[u]){
                in[v]--;
                if(!in[v])q.push(v);
            }
        }
        for(int i=0;i<n;i++){
            if(in[i])return vector<int>();
        }
        return ans;


    }
};
// @lc code=end

