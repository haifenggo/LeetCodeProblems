/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size()-1,p0=0,p1=0;
        for(int i=0;i<=n;i++){
            if(nums[i]==0){
                swap(nums[i],nums[p0]);
                if(p0==p1){
                    p0++,p1++;
                }else{
                    swap(nums[i],nums[p1]);
                    p1++,p0++;
                }
            }else if(nums[i]==1){
                swap(nums[i],nums[p1]);
                p1++;
            }
        }
    }
};
// @lc code=end

