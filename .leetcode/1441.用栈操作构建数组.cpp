/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>stk;
        int siz=target.size();
        int i=0,cnt=1;
        vector<string>ans;
        while(i<siz){
            while(target[i]!=cnt){
                ans.push_back("Push");
                ans.push_back("Pop");
                cnt++;
            }
            ans.push_back("Push");
            i++;
            cnt++;
        }
        return ans;
    }
};
// @lc code=end

