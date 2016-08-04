#include "../header.h"

/**Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2. The number of elements initialized in nums1
and nums2 are m and n respectively.
*/

/*method 1. 首先将B的元素添加到A的后面，然后在对A进行排序。时间复杂度O(nlogn)
* method 2. A 和 B 都是排好序的数组，并且A有足够的元素容纳B。因此，
   可以从最后一个元素开始合并。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m+n-1;
        int i = m - 1;
        int j = n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[tail--] = nums1[i--];
            }else {
                nums1[tail--] = nums2[j--];
            }
        }
    }
};

