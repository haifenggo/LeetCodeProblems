/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int m, int n) {
        vector<vector<pair<int,int>>>g(n);
        vector<int>dis(n,m+1);
        for(auto& e:edges){
            g[e[0]].push_back({e[2],e[1]});
            g[e[1]].push_back({e[2],e[0]});
        }
        dis[0]=0;
        vector<bool>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        while(!q.empty()){
            auto [d,u]=q.top();
            q.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(auto [cost,v]:g[u]){
                if(cost+d+1<dis[v]){
                    dis[v]=d+cost+1;
                    q.push({dis[v],v});
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            // cout<<dis[i]<<" ";
            if(dis[i]<=m){
                ans++;
            }
        }
        // cout<<"\n"<<ans<<'\n';
        for(auto &e:edges){
            int cnt=0;
            int u=e[0],v=e[1],cost=e[2];
            if(dis[u]<=m){
                cnt+=m-dis[u];
            }
            if(dis[v]<=m){
                cnt+=m-dis[v];
            }
            ans+=min(cost,cnt);
        }
        return ans;
    }
};
// @lc code=end

