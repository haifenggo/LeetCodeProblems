/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);
        stack<int>stk;
        stk.push(0);
        for(int i=1;i<temperatures.size();i++){
            while(!stk.empty()){
                if(temperatures[i]>temperatures[stk.top()]){
                    ans[stk.top()]=(i-stk.top());
                    stk.pop();
                }else{
                    break;
                }
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()]=0;
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end

