/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
public:
    vector<int>origin;
    Solution(vector<int>& nums):origin(move(nums)) {

    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int>ans(origin);
        if(ans.empty()){return {};};
        int n=ans.size();
        for(int i=n-1;i>=0;i--){
            swap(ans[i],ans[rand()%(i+1)]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

