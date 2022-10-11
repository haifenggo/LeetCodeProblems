/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int,vector<int>,greater<int>>q;
        q.push(1);
        int x=1;
        while(n--){
            x=q.top();
            q.pop();
            for(int & a:primes){
                if(a<=INT_MAX/x)q.push(x*a);
                if(x%a==0)break;
            }
        }
        return x;
    }
};
// @lc code=end

