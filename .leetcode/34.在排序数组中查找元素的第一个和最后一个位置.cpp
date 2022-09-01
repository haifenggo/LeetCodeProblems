/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){return vector<int>{-1,-1};}
        int l=0,r=n,mid=0;
        int rl=0,rr=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        rl=r;
        if(rl==n||nums[rl]!=target){return vector<int>{-1,-1};}
        l=0,r=n;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]<=target){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        rr=r-1;
        return vector<int>{rl,rr};
        }
};
// @lc code=end

