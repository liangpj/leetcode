#include "../header.h"

/** 3Sum
Given an array S of n integers, are there elements a, b, c in S
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i = 0, last = nums.size()-1;
    while(i < last-1) {
        int a = nums[i];
        int j = i+1, k = last;
        while(j < k) {
            int b = nums[j], c = nums[k];
            int sum = a + b + c;
            if (sum == 0)
                res.push_back({a, b, c});
            if (sum <= 0) //去掉相同的index
                while(nums[j] == b && j < k) ++j;
            if (sum >= 0)
                while(nums[k] == c && j < k) --k;
        }
        while(nums[i] == a && i < last-1) ++i;
    }
    return res;
}

//int main()
//{
//    vector<int> nums = {-1, 0, 1, 2, -1, -4};
//    auto res = threeSum(nums);
//    for (auto e : res) {
//        for (auto i : e)
//            cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}
