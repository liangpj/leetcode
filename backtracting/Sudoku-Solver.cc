#include "../header.h"

/**Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/


class Solution {
public:
    void solveSudoku(vector<string>& board) {
        sudoku(board, 0, 0);
    }
private:
    bool sudoku(vector<string> &board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return sudoku(board, i+1, 0); //处理下一行

        //如果当前坐标不为空则直接处理下一列
        if (board[i][j] != '.') return sudoku(board, i, j+1);

        //board[i][j]有0-9的取值
        for (char ch = '1'; ch <= '9'; ++ch) {
            if (isValidSudoku(board, i, j, ch)) {
                board[i][j] = ch;
                if (sudoku(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    //判断board[r][c] = num是否可以构成一个数独
    bool isValidSudoku(vector<string>& board, int r, int c, char num) {
        //检查行或列是否已经出现过
        for(int i = 0; i < 9; ++i)
            if (board[r][i] == num || board[i][c] == num)
                return false;
        //检查块是否已经出现过
        int row = r/3 * 3, col = c/3 * 3;
        for (int i = row; i < row+3; ++i)
            for (int j = col; j < col+3; ++j)
                if (board[i][j] == num)
                    return false;
        return true;
    }
};
//
//int main()
//{
//    vector<string> board = {"..9748...","7........",".2.1.9...","..7...24.",
//        ".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
//    Solution s;
//    s.solveSudoku(board);
//    for (auto s : board)
//        cout << s << endl;
//    return 0;
//}
