/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<bool>l,r,h;
    vector<vector<string>> solveNQueens(int n) {
        l.resize(2*n-1),r.resize(2*n-1),h.resize(n);
        vector<string>mp(n,string(n,'.'));
        vector<vector<string>>ans;
        backtracking(ans,mp,0,n);
        return ans;
    }
    void backtracking(vector<vector<string>>&ans,vector<string>&mp,int row,int n){
        if(row==n){
            ans.push_back(mp);
            return;
        }
        for(int i=0;i<n;i++){
            if(l[n+i-row-1]||r[row+i]||h[i]){
                continue;
            }
            mp[row][i]='Q';
            l[n+i-row-1]=r[row+i]=h[i]=true;
            backtracking(ans,mp,row+1,n);
            mp[row][i]='.';
            l[n+i-row-1]=r[row+i]=h[i]=false;
        }

    }
};
// @lc code=end

