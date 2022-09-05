/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    vector<int>d{-1,0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        bool f=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(f)return f;
                if(word[0]==board[i][j]){
                    backtracking(f,i,j,0,board,word);
                }
            }
        }
        return f;
    }
    void backtracking(bool &f,int x,int y,int k,vector<vector<char>>& board,const string& word){
        int m=board.size(),n=board[0].size();
        if(f||k==word.size()){
            f=true;
            return;
        }
        if(x<0||y<0||x>=m||y>=n||word[k]!=board[x][y]){
            return ;
        }
        for(int i=0;i<4;i++){
            char ch=board[x][y];
            board[x][y]='1';
            backtracking(f,x+d[i],y+d[i+1],k+1,board,word);
            board[x][y]=ch;
        }
    }
};
// @lc code=end

