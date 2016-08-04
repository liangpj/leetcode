
#include "../header.h"

/** single-number-ii
Given an array of integers, every element appears three times except for one.
Find that single one.
Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/

int singleNumberII(vector<int>& nums)
{
    int x1, x2, mask;
    x1 = x2 = mask = 0;
    for(int i : nums)
    {
        x2 ^= (x1 & i);
        x1 ^= i;
        mask = ~(x1 & x2);
        x1 &= mask;
        x2 &= mask;
    }
    return x1;
}


int single_number_main()
{
    vector<int> nums = {1,1,1,2,2,2,3,4,4,4};
    cout << singleNumberII(nums) << endl;

    return 0;
}
