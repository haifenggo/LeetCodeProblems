/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int>f(n+1,1);
        int ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(pairs[i-1][0]>pairs[j-1][1]){
                    f[i]=max(f[i],f[j]+1);
                }
            }
            ans=max(ans,f[i]);
        }
        return ans;
    }
};
// @lc code=end

