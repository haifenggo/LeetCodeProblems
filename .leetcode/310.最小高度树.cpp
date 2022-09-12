/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>edge;
    void dfs(int& len,int& mx,int origin,vector<int>&parent,vector<int>&dis){
        for(int each:edge[origin]){
            if(dis[each]<0){
                dis[each]=dis[origin]+1;
                if(dis[each]>len){len=dis[each];mx=each;}
                parent[each]=origin;
                dfs(len,mx,each,parent,dis);
            }
        }
    }
    
    // int findlongest(int origin,vector<int>&parent){
        
    //     int n=edge.size();
    //     vector<bool>vis(n);
    //     queue<int>q;
    //     q.push(origin);
    //     int ret=-1;
    //     while(!q.empty()){
    //         int cur=q.front();
    //         q.pop();
    //         vis[cur]=1;
    //         for(int each:edge[cur]){
    //             if(!vis[each]){
    //                 parent[each]=cur;
    //                 ret=each;
    //                 q.push(each);  
    //             }
    //         }
    //     }
    //     return ret;
        
    // }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        edge.resize(n);
        if(n==1){
            return {0};
        }
        for(auto a:edges){
            edge[a[0]].push_back(a[1]);
            edge[a[1]].push_back(a[0]);
        }
        vector<int>parent(n);
         vector<int>dis(n,-1);
        int len=-1,mx=-1;
        dis[0]=0;
        dfs(len,mx,0,parent,dis);
        int x=mx;
        len=-1,mx=-1;
        for(int i=0;i<n;i++)dis[i]=-1;
        dis[x]=0;
        dfs(len,mx,x,parent,dis);
        int y=mx;
        // int x=findlongest(0,parent);
        // int y=findlongest(x,parent);
        vector<int>path;
        parent[x]=-1;
        // return {x};
        while(y!=-1){
            path.push_back(y);
            y=parent[y];
        }
        int k=path.size();
        if(k%2==0){
            return {path[k/2],path[k/2-1]};
        }
        return {path[k/2]};
        // return {y};
    }
};
// @lc code=end

