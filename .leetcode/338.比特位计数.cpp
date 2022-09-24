/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>f(n+1,0);
        for(int i=1;i<=n;i++){
            if((i&1)==1){
                f[i]=f[i>>1]+1;
            }else{
                f[i]=f[i>>1];
            }
        }
        return f;
    }
};
// @lc code=end

