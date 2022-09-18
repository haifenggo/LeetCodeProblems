/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int f[n+1][2];
        f[1][0]=0;
        f[1][1]=-prices[0];
        for(int i=2;i<=n;i++){
            f[i][0]=max(f[i-1][0],f[i-1][1]+prices[i-1]-fee);
            f[i][1]=max(f[i-1][1],f[i-1][0]-prices[i-1]);
        }
        return f[n][0];
    }
};
// @lc code=end

