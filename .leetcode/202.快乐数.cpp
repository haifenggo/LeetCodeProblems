/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    vector<int>c{4, 16, 37, 58, 89, 145, 42, 20};
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        while(n!=1){
            for(int i=0;i<8;i++){
                if(n==c[i])return false;
            }
            n=getNext(n);
        }
        return n==1;
    }
};
// @lc code=end

