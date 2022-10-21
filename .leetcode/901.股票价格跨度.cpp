/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    stack<pair<int,int>>stk;
    int i=-1;
    StockSpanner() {
        stk.push({-1,INT_MAX});

    }
    
    int next(int price) {
        i++;
        while(price>=stk.top().second){stk.pop();}
        int ans=i-stk.top().first;
        stk.push({i,price});
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

