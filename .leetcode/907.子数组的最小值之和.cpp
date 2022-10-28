/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long ans=0,mod=1e9+7;
        vector<int>l(n),r(n);
        stack<int>k;
        for(int i=0;i<n;i++){
            while(!k.empty()&&arr[k.top()]>arr[i]){
                k.pop();
            }
            l[i]=i-(k.empty()?-1:k.top());
            k.push(i);
        }
        while(!k.empty())k.pop();
        for(int i=n-1;i>=0;i--){
            while(!k.empty()&&arr[k.top()]>=arr[i]){
                k.pop();
            }
            r[i]=(k.empty()?n:k.top())-i;
            k.push(i);
        }
        for(int i=0;i<n;i++){
            ans=ans+(long long)(((r[i]*l[i])%mod)*arr[i])%mod;
            ans%=mod;
        }
        return ans;
    }
};
// @lc code=end

