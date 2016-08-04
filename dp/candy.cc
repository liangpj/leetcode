#include "../header.h"

/**
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


/*
在leetcode上会超时
*/
int candy_dp(vector<int>& ratings)
{
    int n = ratings.size();
    int counter = 0;
    vector<int> dp(n+1, 0);
    vector<int> candys(n, 0);   //每个小孩的糖果数
    dp[1] = 1;
    candys[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (ratings[i] < ratings[i-1]) {
            candys[i] = 1;
            for (int j = i; j > 0; --j) {
                if (ratings[j] < ratings[j-1] && candys[j] >= candys[j-1]) {
                        dp[i] += 1;
                        candys[j-1] += 1;
                }else
                    break;
            }
        }else if (ratings[i] > ratings[i-1]) {
            candys[i] = candys[i-1] + 1;
        } else {
            candys[i] = 1;
        }
        dp[i+1] = dp[i] + candys[i];
    }

    return dp[n];
}

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candys(n, 1);   //刚开始为每个child都分配一个

    for(int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i-1])
            candys[i] = candys[i-1] + 1;
    }

    for(int i = n-1; i > 0; --i) {
        if (ratings[i] < ratings[i-1]) {
            candys[i-1] = max(candys[i-1], candys[i]+1);
        }
    }
    return accumulate(candys.begin(), candys.end(), 0);
}

int candy_main()
{
//    vector<int> ratings = {1,2,2}; // 4
//    vector<int> ratings = {2,2,1};  //4;
    vector<int> ratings = {1,3,4,3,2,1}; // 13

    cout << candy(ratings) << endl;

    return 0;
}
