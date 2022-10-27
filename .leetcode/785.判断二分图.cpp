/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        int n=graph.size();
        vector<int>col(n);
        q.push(graph[0][0]);
        col[graph[0][0]]=1;
        while(!q.empty()){
            int cur=q.front();
            
        }
        

    }
};
// @lc code=end

