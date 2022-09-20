/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution {
public:
    map<int,vector<int>>mp;
    vector<int> beautifulArray(int n) {
        vector<int>ans;
        if(n==1){
            ans.push_back(1);
            return ans;
        }
        if(mp.count(n)){return mp[n];}
        int odd=(n+1)/2;
        int even=n/2;
        vector<int>left=beautifulArray(odd);
        vector<int>right=beautifulArray(even);
        for(auto& i:left){
            ans.push_back(2*i-1);
        }
        for(auto& i:right){
            ans.push_back(2*i);
        }
        mp[n]=ans;
        return ans;
    }
};
// @lc code=end

