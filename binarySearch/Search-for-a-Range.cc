#include "../header.h"

/**Search for a Range
Given a sorted array of integers, find the
starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

vector<int> searchRange(vector<int>& nums, int target)
{
    int left = 0, right = nums.size()-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target) {
            right = mid-1;
        }else { //找到元素
            int l = mid, r = mid;
            while(l >= 0 && nums[l] == target) --l;
            while(r < nums.size() && nums[r] == target) ++r;
            return {l+1, r-1};
        }
    }
    return {-1, -1};
}


//int main()
//{
//    vector<int> nums = {1};
//    int target = 0;
//    auto range = searchRange(nums, target);
//    cout << range[0] << " " << range[1] << endl;
//
//    return 0;
//}
