/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    int findk(vector<int>& nums1, vector<int>& nums2,int k){
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        while(true){
            if(i==n1){
                return nums2[j+k-1];
            }
            if(j==n2){
                return nums1[i+k-1];
            }
            if(k==1){
                return min(nums1[i],nums2[j]);
            }
            int ii=min(i+k/2-1,n1-1);
            int jj=min(j+k/2-1,n2-1);
            if(nums1[ii]>=nums2[jj]){
                k-=jj-j+1;
                j=jj+1;
            }else{
                k-=ii-i+1;
                i=ii+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        if(n==0)return 0.0;
        if(n%2==1){
            return findk(nums1,nums2,(n+1)/2)*1.0;
        }else{
            return (findk(nums1,nums2,n/2+1)+findk(nums1,nums2,n/2))/2.0;
        }

    }
};
// @lc code=end

