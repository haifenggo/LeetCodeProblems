/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        bool pre=false;
        int n=a.size()-1,m=b.size()-1;
        if(n>m){
            for(int i=0;i<n-m;i++){
                b="0"+b;
            }
            m=n;
        }else{
             for(int i=0;i<m-n;i++){
                a="0"+a;
            }

        }
        for(int i=m;i>=0;i--){
            if(a[i]=='1'&&b[i]=='1'){
                if(pre){
                    ans="1"+ans;
                }else{
                    ans="0"+ans;
                    pre=true;
                }
            }else if(a[i]=='1'||b[i]=='1'){
                if(pre){
                    ans="0"+ans;
                }else{
                    ans="1"+ans;
                    pre=false;
                }
            }else{
                if(pre){
                    ans="1"+ans;
                    pre=false;
                }else{
                    ans="0"+ans;
                }
            }
        }
        if(pre){
            ans="1"+ans;
        }
        return ans;
    }
};
// @lc code=end

