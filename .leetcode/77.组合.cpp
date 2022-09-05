/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>one;
        backtracking(ans,one,n,k,0,1);
        return ans;
    }
    void backtracking(vector<vector<int>>&ans,vector<int>&one,int n,int k,int size,int i){
        if(size==k){
            ans.push_back(one);
            return;
        }
        for(int j=i;j<=n;j++){
            one.push_back(j);
            backtracking(ans,one,n,k,size+1,j+1);
            one.pop_back();
        }
    }
};
// @lc code=end

