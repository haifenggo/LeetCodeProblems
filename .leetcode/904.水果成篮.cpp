/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int l=0,r=0;
        int ln=fruits[0],rn=fruits[0];
        while(r<fruits.size()){
            if(fruits[r]==ln||fruits[r]==rn){
                ans=max(ans,r-l+1);
            }else{
                l=r-1;
                ln=fruits[l];
                while(l>=1&&fruits[l-1]==ln)l--;
                ans=max(ans,r-l+1);
                rn=fruits[r];
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end

