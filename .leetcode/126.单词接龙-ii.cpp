/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>>ans;
    unordered_set<string>dict={wordList.begin(),wordList.end()};
    if(dict.find(endWord)==dict.end()){
        return ans;
    }
    dict.erase(beginWord);
    unordered_map<string,set<string>>mp={{beginWord,{}}};
    unordered_map<string,int>steps={{beginWord,0}};
    queue<string>q=queue<string>{{beginWord}};
    bool f=false;
    int step=0;
    int len=beginWord.size();
    while(!q.empty()){
        step++;
        int n=q.size();
        for(int i=0;i<n;i++){// every string
            string cur=move(q.front());
            q.pop();
            string nxt=cur;
            for(int j=0;j<len;j++){// 
                char origin=nxt[j];
                for(char ch='a';ch<='z';ch++){
                    nxt[j]=ch;
                    if(steps[nxt]==step){
                        mp[nxt].insert(cur);
                    }
                    if(dict.find(nxt)==dict.end()){// wu
                        continue;
                    }
                    dict.erase(nxt);
                    q.push(nxt);
                    mp[nxt].insert(cur);
                    steps[nxt]=step;
                    if(nxt==endWord){
                        f=true;
                    }
                }
                nxt[j]=origin;
            }
        }
        if(f){ break; }
    }
    if(f){
        vector<string>path={endWord};
        backtracking(ans,endWord,mp,path);
    }
    return ans;
    }
    void backtracking(vector<vector<string>> &res, const string &Node, unordered_map<string, set<string>> &from,vector<string> &path){
        if(from[Node].empty()){
            res.push_back({path.rbegin(),path.rend()});
            return;
        }
        for(auto& p:from[Node]){
            path.push_back(p);
            backtracking(res,p,from,path);
            path.pop_back();
        }

    }

};
// @lc code=end


