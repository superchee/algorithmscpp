#include <vector>

using namespace std;

class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool check(int x, int y, int row, int col){return (x>=0 && y>=0 && x < row && y < col)? true:false;};
    void dfs(int n, int m, vector<vector<char>>& board, int row, int col){
        int x,y;
        if(board[n][m] == 'O'){
            board[n][m] = 'S';
            for(int i = 0; i < 4; i++){
                x = n+dx[i];
                y = m+dy[i];
                if (check(x,y, row, col) && board[x][y]=='O') dfs(n+dx[i],m+dy[i],board, row, col);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row(board.size()), col(board[0].size());

        for(int i = 0; i < col; i++){
            dfs(0,i,board, row, col);
            dfs(row-1,i,board, row, col);
        }

        for(int i = 1; i < row-1; i++){
            dfs(i,0,board, row, col);
            dfs(i,col-1,board, row, col);
        }

        for(int i = 0; i < row; i++){
            for(int j=0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};