/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto& a:s){
            mp[a]+=1;
        }
        vector<pair<char,int>>count;
        for(auto& [ch,i]:mp){
            count.push_back({ch,i});
        }
        sort(count.begin(),count.end(),
        [](const pair<char,int>&a,const pair<char,int>&b){
            return a.second>b.second;
        });
        string str="";
        for(int i=0;i<count.size();i++){
            for(int j=0;j<count[i].second;j++){
                str+=count[i].first;
            }
        }
        return str;
    }
};
// @lc code=end

