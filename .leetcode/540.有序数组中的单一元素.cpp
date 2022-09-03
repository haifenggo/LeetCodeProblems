/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(r==0)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[r]!=nums[r-1])return nums[r];
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==nums[mid^1]){
                l=mid+1;
            }else{
                r=mid;
            }
            // if(nums[mid]==nums[mid-1]){
            //     if(mid%2==0){
            //         r=mid;
            //     }else
            //         l=mid+1;
            // }else if(nums[mid]==nums[mid+1]){
            //     if(mid%2==0){
            //         l=mid+1;
            //     }else
            //         r=mid;
            // }else{
            //     return nums[mid];
            // }
        }
        return nums[l];
    }
};
// @lc code=end

