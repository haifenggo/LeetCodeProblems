/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
public:
    vector<int>sum;
    Solution(vector<int>& w):sum(move(w)) {
        partial_sum(sum.begin(),sum.end(),sum.begin());
    }
    
    int pickIndex() {
        int pos=(rand()%sum.back())+1;
        return lower_bound(sum.begin(),sum.end(),pos)-sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

