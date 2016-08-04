
#include "../header.h"


void solve(vector<vector<char>>& board)
{
    int row = board.size();
    int col = board[0].size();
    for (int i = 1; i < row -1; ++i)
    {
        stack<pair<int,int>> xst;
        for (int j = 1; j < col-1; ++j) {
            char ch = board[i][j];

        }
    }
}

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };

    cout << board.size() << endl;
    cout << board[0].size() << endl;


    return 0;
}
