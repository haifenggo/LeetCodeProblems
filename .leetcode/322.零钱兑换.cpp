/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>f(amount+1,amount+1);
        f[0]=0;
        for(int i=1;i<=amount;i++){
            for(int &coin:coins){
                if(coin<=i){
                    f[i]=min(f[i],f[i-coin]+1);
                }
            }
        }
        return f[amount]==amount+1?-1:f[amount];
    }
};
// @lc code=end

