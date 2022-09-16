/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int>f(n+1,n+1);
        f[1]=0;
        for(int i=2;i<=n;i++){
            f[i]=i;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    f[i]=f[j]+f[i/j];
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

