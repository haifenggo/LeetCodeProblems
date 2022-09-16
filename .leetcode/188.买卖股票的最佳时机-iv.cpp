/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>buy(k+1,-1000000),sell(k+1,0);
        
        for(int i=0;i<n;i++){
            buy[0]=max(buy[0],-prices[i]);
            for(int j=1;j<=k;j++){
                buy[j]=max(buy[j],sell[j]-prices[i]);
                sell[j]=max(sell[j],buy[j-1]+prices[i]);
            }
        }
        return *max_element(sell.begin(),sell.end());
    }
};
// @lc code=end

