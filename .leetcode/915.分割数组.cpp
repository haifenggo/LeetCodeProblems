/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int mx=nums[0],cur=nums[0];
        for(int i=1;i<n-1;i++){
            cur=max(cur,nums[i]);
            if(nums[i]<mx){
                ans=i;
                mx=cur;
            }
        }
        return ans+1;


        // vector<int>mn;
        // int n=nums.size();
        // mn.push_back(nums[n-1]);
        // int mnn=nums[n-1];
        // for(int i=n-2;i>=0;i--){
        //     mnn=min(nums[i],mnn);
        //     mn.push_back(mnn);

        // }
        // int ans=1,mx=nums[0];
        // for(int i=1;i<n;i++){
        //     if(mx>mn[n-i-1]){
        //         ans++;
        //     }else{
        //         break;
        //     }
        //     mx=max(mx,nums[i]);
        // }
        // return ans;

    }
};
// @lc code=end

