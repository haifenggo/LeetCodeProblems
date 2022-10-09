/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size(),m=mat[0].size();
        if(n*m!=r*c){return mat;}
        vector<vector<int>>ans(r,vector<int>(c));
        int i=0,j=0;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                ans[x][y]=mat[i][j];
                j++;
                if(j==m){
                    i++;
                    j=0;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

