/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int i=0;
        return f(s,i);
        

    }
    int f(string& s ,int& i){
        char op='+';
        int l=0,r=0;
        while(i<s.size()){
            if(s[i]!=' '){
                int n=sm(s,i);
                if(op=='+'){
                    l+=r;r=n;
                }else if(op=='-'){
                    l+=r;r=-n;
                }else if(op=='*'){
                    r*=n;
                }else if(op=='/'){
                    r/=n;
                }
                if(i<s.size()){
                    op=s[i];
                }
            }
            i++;
        }
        return l+r;
    }
    long sm(string& s,int& i){
        long ans=0;
        while(i<s.size()&&isdigit(s[i])){
            ans=ans*10+s[i]-'0';
            ++i;
        }
        return ans;
    }
};
// @lc code=end

