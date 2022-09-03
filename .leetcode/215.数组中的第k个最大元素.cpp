/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

class Solution {
public:
    int partition(vector<int>&nums,int l,int r){
        swap(nums[r],nums[l+(r-l)/2]);
        int x=nums[r],i=l-1;
        for(int j=l;j<r;j++){
            if(nums[j]<=x){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);
        return i+1;
    }
    int find(vector<int>&nums,int l,int r,int k){
        int p=partition(nums,l,r);
        if(p==k){
            return nums[p];
        }
        if(p>k){

            return find(nums,l,p-1,k);
        }else{

            return find(nums,p+1,r,k);
        }
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,0,nums.size()-1,nums.size()-k);
        
    }
};
// @lc code=end

