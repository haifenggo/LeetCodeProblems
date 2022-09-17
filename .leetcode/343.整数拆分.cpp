/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int>f(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                f[i]=max(f[i],max(j*(i-j),j*f[i-j]));
            }
        }
        return f[n];
    }
};
// @lc code=end

