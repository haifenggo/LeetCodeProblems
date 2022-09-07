/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    vector<int>d{-1,0,1,0,-1};
    bool check(int x,int y,int n,int m){
        if(x<0||y<0||x>=n||y>=m){
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='a';
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                board[m-1][i]='a';
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='a';
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                board[i][n-1]='a';
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+d[i],dy=y+d[i+1];
                if(dx>=0&&dy>=0&&dx<m&&dy<n){
                    if(board[dx][dy]=='O'){
                        q.push({dx,dy});
                        board[dx][dy]='a';
                    }
                }
            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='a'){
                    board[i][j]='O';
                }
            }
        }
    }
};
// @lc code=end

