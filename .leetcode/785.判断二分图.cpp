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
        for(int i=0;i<n;i++){
            if(!col[i]){
                q.push(i);
                col[i]=1;
                
            }
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(int& to:graph[cur]){
                    if(!col[to]){
                        q.push(to);
                        col[to]=col[cur]==1?2:1;
                    }
                    else if(col[to]==col[cur])return false;
                    

                }

            }
        }
        return true;

    }
};
// @lc code=end

