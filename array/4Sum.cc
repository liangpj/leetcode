#include "../header.h"

/**4Sum
Given an array S of n integers, are there elements a, b, c,
and d in S such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i = 0, last = nums.size()-1;
    while(i < last-2) {
        int a = nums[i], j = i + 1;
        while (j < last-1) {
            int b = nums[j], k = j+1, x = last;
            while(k < x) {
                int c = nums[k], d = nums[x];
                int sum = a + b + c + d;
                if (sum == target)
                    res.push_back({a, b, c, d});
                if (sum <= target)
                    while(nums[k] == c && k < x) ++k;
                if (sum >= target)
                    while(nums[x] == d && k < x) --x;
            }
            while (nums[j] == b && j < last-1) ++j;
        }
        while (nums[i] == a && i < last-2) ++i;
    }
    return res;
}

//int main()
//{
//    vector<int> nums = {1, 0, -1, 0, -2, 2};
//    int target = 0;
//    auto res = fourSum(nums, target);
//    for(auto e : res) {
//        for (int i : e)
//            cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}
