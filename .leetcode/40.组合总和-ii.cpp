/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<bool>vis;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vis.resize(candidates.size());
        vector<int>one;
        vector<vector<int>>ans;
        dfs(one,ans,candidates,0,0,target);
        return ans;
    }
    void dfs(vector<int>&one,vector<vector<int>>&ans,vector<int>& candidates,int k,int tot,int target){
       if(tot==target){
            ans.push_back(one);
            return;
        }
        if(k==candidates.size()||tot>target){return;}
        
        int i=k;
        if(!(vis[i]||(i>0&&candidates[i]==candidates[i-1]&&!vis[i-1]))){
            one.push_back(candidates[i]);
            vis[i]=1;
            dfs(one,ans,candidates,i+1,tot+candidates[i],target);
            one.pop_back();
            vis[i]=0;
        }
        dfs(one,ans,candidates,i+1,tot,target);
    
        
    }
};
// @lc code=end

