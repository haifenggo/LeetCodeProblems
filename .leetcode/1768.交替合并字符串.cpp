/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n1=w1.size(),n2=w2.size();
        string ans="";
        if(n1<n2){
            for(int i=0;i<n1;i++){
                ans+=w1[i];
                ans+=w2[i];
            }
            for(int i=n1;i<n2;i++){
                ans+=w2[i];
            }
        }else{
            for(int i=0;i<n2;i++){
                ans+=w1[i];
                ans+=w2[i];
            }
            for(int i=n2;i<n1;i++){
                ans+=w1[i];
            }
        }
        return ans;
    }
};
// @lc code=end

