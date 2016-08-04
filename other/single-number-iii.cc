#include "../header.h"

/**
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant space complexity?
*/

vector<int> singleNumberIII(vector<int>& nums)
{
    vector<int> res;
    sort(nums.begin(), nums.end());
    int i = 0, index=0;
    while (i < nums.size()-1) {
        if (nums[i] != nums[i+1]) {
            res.push_back(nums[i]);
            i += 1;
        }
        else {
            i += 2;
        }
        if (i == nums.size() -1)
            res.push_back(nums[i]);
    }
    return res;
}

int singleIII_main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    int diff = 0;

    auto res = singleNumberIII(nums);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
