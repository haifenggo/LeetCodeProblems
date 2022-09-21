/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        string cmp="s";
        while(columnNumber!=0){
            char ch='A'+(columnNumber%26+25)%26;
            cmp[0]=ch;
            s=cmp+s;
            if (columnNumber % 26 == 0) {
                columnNumber -= 26;
            }
            columnNumber/=26;
        }
        return s;
    }
};
// @lc code=end

