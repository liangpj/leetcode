#include "../header.h"

/** Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity.
Could you implement it using only constant extra space complexity?
*/


/*此题比较简单
1. 可以先对数组进行排序。然后在进行查找 O(nlogn)
2. 使用算术求和公式。将[0,n]的减去nums的和就是所求的答案。O(n)
3. 使用XOR, 因为a^a = 0,a^0 = a;
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); ++i)
        //     if (i != nums[i])
        //         return i;
        // return nums.size();

//        auto diff = accumulate(nums.begin(), nums.end(), 0);
//        int n = nums.size()+1;
//        int sum = (n-1)*n/2;
//        return sum - diff;
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i]^i;
        }
        return res;
    }
};
