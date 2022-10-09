/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int>n;
    NumArray(vector<int>& nums) {
        n.resize(nums.size()+1);
        n[0]=0;
        for(int i=1;i<=nums.size();i++){
            n[i]=n[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return n[right+1]-n[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

