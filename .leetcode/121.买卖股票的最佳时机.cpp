/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=100000,ans=0;
        for(int price:prices){
            mn=min(price,mn);
            ans=max(ans,price-mn);
        }
        return ans;
    }
};
// @lc code=end

