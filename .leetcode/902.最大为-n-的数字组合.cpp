/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        int m=s.size(),k=digits.size();
        vector<vector<int>>f(m+2,vector<int>(2));
        f[0][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<k;j++){
                if(digits[j][0]==s[i-1]){
                    f[i][1]=f[i-1][1];
                }else if(digits[j][0]<s[i-1]){
                    f[i][0]+=f[i-1][1];
                }else{
                    break;
                }
            }
            if(i>1){
                f[i][0]+=k+f[i-1][0]*k;
            }
        }
        return f[m][1]+f[m][0];
    }
};
// @lc code=end

