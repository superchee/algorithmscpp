#include <vector>

using namespace std;

class Solution {
    int backtrack(vector<vector<char>>& board, int i, int j, int* row, int* col, int* blk){
        if (i == 9) return true;
        if (j == 9) return backtrack(board, i+1, 0, row, col, blk);
        if (board[i][j] != '.'){
            return backtrack(board, i, j+1, row, col, blk);
        }else{
            for(int k = 1; k < 10; k++){
                if ((row[i]&(1<<k)) || (col[j]&(1<<k)) || (blk[(i/3)*3+j/3]&(1<<k))) continue;

                row[i] += (1<<k);
                col[j] += (1<<k);
                blk[(i/3)*3+j/3] += (1<<k);

                board[i][j] = '0' + k;

                if(backtrack(board, i, j+1, row, col, blk)){
                    return true;
                }else{
                    row[i] -= (1<<k);
                    col[j] -= (1<<k);
                    blk[(i/3)*3+j/3] -= (1<<k);
                    board[i][j] = '.';
                }

            }
        }
        return false;

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int row[9]={0}, col[9]={0}, blk[9]={0};
        int temp(0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    temp = board[i][j] - '0';
                    row[i] += (1<<temp);
                    col[j] += (1<<temp);
                    blk[(i/3)*3+j/3] += (1<<temp);
                }
            }
        }

        backtrack(board, 0, 0, row, col, blk);
    }
};