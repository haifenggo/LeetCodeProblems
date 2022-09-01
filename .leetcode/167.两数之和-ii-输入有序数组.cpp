/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        vector<int>ans;
        while(l<r){
            if(numbers[l]+numbers[r]<target){
                l++;
            }else if(numbers[l]+numbers[r]>target){
                r--;
            }else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        ans.push_back(l+1);
        ans.push_back(r+1);
        return ans;
    }
};
// @lc code=end

