/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int XOR=0;
        for(const int& num:nums){
            XOR^=num;
        }
        int a=0,b=0;
        int lowbit=XOR&(-XOR);
        for(const int& num:nums){
            if(num&lowbit){
                a^=num;
            }else{
                b^=num;
            }
        }
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
// @lc code=end

