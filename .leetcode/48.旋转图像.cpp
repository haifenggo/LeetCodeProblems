/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int t=0,n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                t=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-1-i][n-j-1];
                matrix[n-1-i][n-j-1]=matrix[j][n-1-i];
                matrix[j][n-1-i]=t;

            }
        }
        
    }
};
// @lc code=end

