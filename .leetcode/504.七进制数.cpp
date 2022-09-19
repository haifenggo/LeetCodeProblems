/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){return "0";}
        bool f=0;
        if(num<0)f=1,num=-num;
        string ans;
        while(num){
            int a=num/7,b=num%7;
            ans=to_string(b)+ans;
            num=a;
        }
        return f?"-"+ans:ans;
    }
};
// @lc code=end

