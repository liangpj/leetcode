#include "../header.h"

/**Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows);
    for(int i = 0; i < numRows; ++i) {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; ++j)
            res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}

int pascal_main()
{
    auto res = generate(5);
    for(const auto i : res) {
        for(const auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
