/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                }else{
                    if(i==0&&j==0){
                        ans[i][j]=10001;
                    }
                    else if(i==0){
                        ans[i][j]=ans[i][j-1]+1;
                    }else if(j==0){
                        ans[i][j]=ans[i-1][j]+1;
                    }else{
                        ans[i][j]=min(ans[i][j-1],ans[i-1][j])+1;
                    }
                }
            }
        }
          for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                }else{
                    if(i==n-1&&j==m-1){
                        
                    }
                    else if(i==n-1){
                        ans[i][j]=min(ans[i][j+1]+1,ans[i][j]);
                    }else if(j==m-1){
                        ans[i][j]=min(ans[i+1][j]+1,ans[i][j]);
                    }else{
                        ans[i][j]=min(min(ans[i][j+1],ans[i+1][j])+1,ans[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

