/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int>f(n+1,10004);
        f[1]=1;f[0]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                f[i]=min(f[i],f[i-j*j]+1);
            }
        }
        return f[n];
    }
};
// @lc code=end

