/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visit(isConnected.size(),false);
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visit[i]){
                ans++;
                visit[i]=true;
                dfs(isConnected,visit,i);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& isConnected,vector<bool>&visit,int k){
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            if(isConnected[k][i]==1&&!visit[i]){
                visit[i]=true;
                dfs(isConnected,visit,i);
            }
        }
    }
};
// @lc code=end

