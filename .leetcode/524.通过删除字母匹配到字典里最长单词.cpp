/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),
        [](const string&a,const string& b){
            int n=a.size(),m=b.size();
            if(n!=m){
                return n>m;
            }else{
                for(int i=0;i<n;i++){
                    if(a[i]==b[i]) continue;
                    return a[i]<b[i];
                }
                return a[0]==b[0];
            }
        });
        for(string t:dictionary){
            int n=s.size(),m=t.size();
            int l=0,r=0;
            while(l<n&&r<m){
                if(s[l]==t[r]){
                    r++;
                }
                l++;
            }
            if(r==m){
                return t;
            }
        }
        return "";
    }
};
// @lc code=end

