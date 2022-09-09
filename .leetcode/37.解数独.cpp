/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool find;
    vector<pair<int,int>>space;
    int col[9][9];
    int row[9][9];
    int maze[3][3][9];
    void dfs(vector<vector<char>>& board,int pos){
        if(find||space.size()==pos){
            find=true;
            return;
        }
        auto [x,y]=space[pos];
        for(int i=0;i<9&&!find;i++){
            if(!(col[y][i]||row[x][i]||maze[x/3][y/3][i])){
                char ch=i+'0'+1;
                col[y][i]=row[x][i]=maze[x/3][y/3][i]=true;
                board[x][y]=ch;
                dfs(board,pos+1);
                col[y][i]=row[x][i]=maze[x/3][y/3][i]=false;
            }
            
            
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    space.push_back({i,j});
                }else{
                    int num=board[i][j]-'0'-1;
                    col[j][num]=row[i][num]=maze[i/3][j/3][num]=true;
                }
            }
        }
        dfs(board,0);
        return;
    }
};
// @lc code=end

