/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),
        [](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        });
        int n=people.size();
        vector<vector<int>>ans(n);
        for(auto peoson:people){
            int space=peoson[1]+1;
            for(int i=0;i<n;i++){
                if(ans[i].empty())space--;
                if(!space){
                    ans[i]=peoson;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

