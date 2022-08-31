/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>last(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end=max(end,last[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};
// @lc code=end

