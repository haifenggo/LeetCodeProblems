/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int w=prices[i]-prices[i-1];
            if(w>0)ans+=w;
        }
        return ans;
    }
};
// @lc code=end

