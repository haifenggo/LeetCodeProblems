/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:

    int majorityElement(vector<int>& nums) {
        int other,ans=nums[0];
        int no=0,na=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans){
                na++;
            }else{
                no++;
                other=nums[i];
                if(na<no)
                    swap(other,ans),swap(no,na);
            }

        }
        if(na>no)return ans;
        return other;
    }
};
// @lc code=end

