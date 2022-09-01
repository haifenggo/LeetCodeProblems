/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){return true;}
            if(nums[l]==nums[mid]){l++;}
            else if(nums[r]>=nums[mid]){
                if(target>nums[mid]&&target<=nums[r]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }else{
                if(target<nums[mid]&&target>=nums[l]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return false;
    }
};
// @lc code=end

