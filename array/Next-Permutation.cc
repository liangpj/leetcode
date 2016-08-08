#include "../header.h"

/**Next Permutation
Implement next permutation, which rearranges numbers into
the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order
(ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its
corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        helper(nums, 0);
    }

private :
    void helper(vector<int> &nums, int start) {
        if (start == nums.size()-1)
            return;
        for (int i = nums.size()-1; i >= start; --i) {
            for (int j = 1; j < nums.size()-start; ++j) {
                if (i-j >= start && nums[j] > nums[j-i]) {
                    swap(nums, i, i-j);
                    helper(nums, i-j+1);
                    return;
                }
            }
        }
        reverse(nums.begin()+start, nums.end());
    }
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
    }
};

//int main()
//{
//    vector<int> nums = {1,3,2};
//    Solution s;
//    s.nextPermutation(nums);
//    for (auto i : nums)
//        cout << i << " ";
//    cout << endl;
//
//    return 0;
//}
