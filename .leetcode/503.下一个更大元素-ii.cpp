/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>stk;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
            while(!stk.empty()&&nums[stk.top()%n]<nums[i]){
                ans[stk.top()%n]=nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for(int i=n;i<2*n;i++){
            while(!stk.empty()&&nums[stk.top()%n]<nums[i]){
                ans[stk.top()%n]=nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

