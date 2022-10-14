/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        deque<int>q;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(!q.empty()&&mp[s[i]]>=2){
                mp[s[q.front()]]--;
                q.pop_front();
            }
            q.push_back(i);
            ans=max(ans,i-q.front()+1);
        }
        return ans;
    }
};
// @lc code=end

