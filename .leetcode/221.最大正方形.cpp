/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>>f(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    f[i][j]=0;
                }else{
                    if(i==0||j==0){
                        f[i][j]=1;
                        ans=max(ans,1);
                    }else{
                        f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
                        ans=max(ans,f[i][j]);
                    }
                }
            }
        }
        return ans*ans;
    }
};
// @lc code=end

