#include "../header.h"

/** Valid Sudoku
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable.
Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<string>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));  //检查行
        vector<vector<bool>> cols(9, vector<bool>(9, false));   //检查列
        vector<vector<bool>> block(9, vector<bool>(9, false));  //检查块

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = int(board[i][j] - '0') - 1;
                int k = i/3 * 3 + j/3;
                if (rows[i][num] || cols[j][num] || block[k][num])
                    return false;
                rows[i][num] = cols[j][num] = block[k][num] = true;
            }
        }
        return true;
    }
};

//int main()
//{
//    vector<string> board = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.",
//         "...54....","3.....42.","...27.6.."};
//    Solution s;
//    cout << s.isValidSudoku(board) << endl;
//
//    return 0;
//}
