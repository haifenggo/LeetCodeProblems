/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size()-1,m=matrix[0].size()-1;
        int i=0,j=m;
        while(matrix[i][j]!=target){
            if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
            if(i>n||j<0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

