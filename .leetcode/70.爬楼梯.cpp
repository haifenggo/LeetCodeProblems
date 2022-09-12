/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1){return 1;}
        int a=1,b=2,c=0;
        n-=2;
        while(n--){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
// @lc code=end

