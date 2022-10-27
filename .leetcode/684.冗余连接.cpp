/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    int find(int x,vector<int>&f){
        if(f[x]!=x){
            f[x]=find(f[x],f);
        }
        return f[x];
    }
    void merge(int x,int y,vector<int>&f){
        f[find(x,f)]=find(y,f);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>f(edges.size()+1);
        for(int i=0;i<edges.size();i++){
            f[i+1]=i+1;
        }
        for(auto& e:edges){
            int x=e[0],y=e[1];
            if(find(x,f)==find(y,f)){
                return e;
            }else{
                merge(x,y,f);
            }
        }
        return vector<int>{1,2};
    }
};
// @lc code=end

