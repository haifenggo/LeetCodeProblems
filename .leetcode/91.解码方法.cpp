/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){return 0;}
        int n=s.size();

        int pre=s[0]-'0';
        int a=1,b=1,c=1;
        for(int i=2;i<=n;i++){
            int cur=s[i-1]-'0';
            if((pre==0||pre>2)&&cur==0){
                return 0;
            }
            if(cur==0){
                c=a;
            }else if(pre==1||(pre==2&&cur<=6)){
                c=a+b;
            }else{
                c=b;
            }
            pre=cur;
            a=b;
            b=c;
        }
        return c;

        // vector<int>f(n+1,1);
        // int pre=s[0]-'0';
        // for(int i=2;i<=n;i++){
        //     int cur=s[i-1]-'0';
        //     if((pre==0||pre>2)&&cur==0){
        //         return 0;
        //     }
        //     if(cur==0){
        //         f[i]=f[i-2];
        //     }
        //     else if(pre==1||(pre==2&&cur<=6)){
        //         f[i]=f[i-1]+f[i-2];
        //     }else{
        //         f[i]=f[i-1];
        //     }
        //     pre=cur;
        // }
        // return f[n];
    }
    
};
// @lc code=end

