/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int d1=-prices[0],d2=0,d3=0;
        for(int i=1;i<n;i++){
            int dd1=max(d1,d3-prices[i]);
            int dd2=d1+prices[i];
            int dd3=max(d2,d3);
            d1=dd1;d2=dd2;d3=dd3;
        }
        return max(d2,d3);
    }
};
// @lc code=end

