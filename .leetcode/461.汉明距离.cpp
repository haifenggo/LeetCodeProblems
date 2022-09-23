/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int k=x^y,ans=0;
        while(k){
            ans+=k&1;
            k>>=1;
        }
        return ans;
    }
};
// @lc code=end

