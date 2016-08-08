#include "../header.h"

/**3Sum Closest
Given an array S of n integers, find three integers in S such that
the sum is closest to a given number, target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    int last = nums.size()-1;

    int i = 0;
    while(i < last-1) {
        int a = nums[i];
        int j = i + 1, k = last;
        while(j < k) {
            int b = nums[j], c = nums[k];
            int sum = a + b + c;
            if (abs(sum-target) < abs(res-target))
                res = sum;
            if (sum-target == 0)
                return sum;
            if (sum < target)
                while(nums[j] == b && j < k) ++j;
            if (sum > target)
                while(nums[k]==c && j < k) --k;
        }
        while(nums[i] == a && i < last-1)
            ++i;
    }
    return res;
}

//int main()
//{
//    vector<int> nums = {-1, 2, 1, -4};
//    int target = 2;
//    cout << threeSumClosest(nums, target)<< endl;
//    return 0;
//}
