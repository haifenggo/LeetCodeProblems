/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    vector<int>d{-1,0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int mx=0,area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area=1;
                    stack<pair<int,int>>stk;
                    stk.push({i,j});
                    grid[i][j]=0;
                    while(!stk.empty()){
                        auto [i,j]=stk.top();
                        stk.pop();
                        for(int k=0;k<4;k++){
                            int di=i+d[k],dj=j+d[k+1];
                            if(di>=0&&dj>=0&&di<m&&dj<n&&grid[di][dj]==1){
                                area++;
                                grid[di][dj]=0;
                                stk.push({di,dj});
                            }
                        }
                    }
                    mx=max(mx,area);
                }
            }
        }
        return mx;
    }
};
// @lc code=end

