#include "../header.h"

/**Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

/*
 Time Limit Exceeded
*/
int maxProfit_dp(vector<int>& prices)
{
    int n = prices.size();
    vector<int> dp(n, 0);

    if (n < 2) return 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i-1];
        for (int j = 0; j < i; ++j) {
            dp[i] = max(dp[i], prices[i]-prices[j]);
        }
    }
    return dp[n-1];
}

int maxProfit(vector<int>& prices)
{
    int mini = INT_MAX; //保存ith之前的最小值
    int profit = 0;

    for (int i = 0; i < prices.size(); ++i) {
        profit = max(profit, prices[i]-mini);
        mini = min(mini, prices[i]);
    }
    return profit;
}

//int main()
//{
//    vector<int> prices = {7, 1, 5, 3, 6, 4};
////    vector<int> prices = {7, 6, 4, 3, 1};
//    cout << maxProfit(prices) << endl;
//
//    return 0;
//}


