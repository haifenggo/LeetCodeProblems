/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0,pre=0,cur=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cur++;
            }else{
                pre=cur;
                cur=1;
            }
            if(pre>=cur){ans++;}
        }
        return ans;

    }
};
// @lc code=end

