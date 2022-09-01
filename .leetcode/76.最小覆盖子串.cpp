/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<bool>chars(128,false);
        vector<int>num(128,0);
        for(int i=0;i<t.size();i++){
            chars[t[i]]=true;
            num[t[i]]++;
        }
        int cnt=0,l=0,min_l=0,min_size=s.size()+1;
        for(int i=0;i<s.size();i++){
            if(chars[s[i]]){
                num[s[i]]--;
                if(num[s[i]]>=0){
                    cnt++;
                }
            }
            while(cnt==t.size()){
                if(i-l+1<min_size){
                    min_l=l;
                    min_size=i-l+1;
                }
                if(chars[s[l]]&&++num[s[l]]>0){
                    cnt--;
                }
                l++;
            }
        }
        return min_size<=s.size()?s.substr(min_l,min_size):"";
    }
};
// @lc code=end

