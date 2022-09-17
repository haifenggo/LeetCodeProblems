/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        int a=nums[0],b=max(nums[0],nums[1]),ans=0;
        for(int i=2;i<n;i++){
            a=a+nums[i];
            if(a>b){
                ans=a;
                swap(a,b);
            }else{
                ans=b;
                a=b;
            }
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        return max(rob1(v1),rob1(v2));
        // return v1[1];
    }
};
// @lc code=end

