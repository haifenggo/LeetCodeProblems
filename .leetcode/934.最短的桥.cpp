/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    vector<int>d{-1,0,1,0,-1};
    bool check(int x,int y,int n,int m){
        if(x<0||y<0||x>=n||y>=m){
            return false;
        }
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        queue<pair<int,int>>one;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,n,one);
                    bfs(grid,i,j,ans,one);
                    return ans-1;
                }
            }
        }
        return 0;
    }
    void bfs(vector<vector<int>>& grid,int x,int y,int& ans,queue<pair<int,int>>&one){
        
        while(!one.empty()){
            ans++;
            int n=one.size();
            while(n--){
                auto [r,c]=one.front();
                one.pop();
                for(int i=0;i<4;i++){
                    int dx=r+d[i],dy=c+d[i+1];
                    if(check(dx,dy,grid.size(),grid.size())){
                        if(grid[dx][dy]==1){
                            return;
                        }
                        else if(grid[dx][dy]==0){
                            grid[dx][dy]=2;
                            one.push({dx,dy});
                        }   
                    }
                }
            }
        }

    }
    void dfs(vector<vector<int>>& grid,int x,int y,int n,queue<pair<int,int>>&one){
        one.push({x,y});
        grid[x][y]=2;
        for(int i=0;i<4;i++){
            if(check(x+d[i],y+d[i+1],n,n)&&grid[x+d[i]][y+d[i+1]]==1){
                dfs(grid,x+d[i],y+d[i+1],n,one);
            }
        }
    }
};
// @lc code=end

