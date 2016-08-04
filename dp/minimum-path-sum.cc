#include "../header.h"

/**minimum-path-sum
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int val = 0;
            bool flag = false;
            if (i-1>=0) {
                val = dp[i-1][j];
                flag = true;
            }
            if (j-1 >=0) {
                val = flag ? min(val, dp[i][j-1]) : dp[i][j-1];
            }
            dp[i][j] = grid[i][j] + val;
        }
    }
    for(const auto row : dp) {
        for(auto i : row)
            cout << i << " ";
        cout << endl;
    }
    return dp[m-1][n-1];

}

int min_path_sum_main()
{
    vector<vector<int>> grid = {{1,3,1}, {1,5, 1}, {4,2,1}};
    cout << minPathSum(grid) << endl;
    return 0;
}

