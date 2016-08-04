#include "../header.h"

/**longest-consecutive-sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.
Your algorithm should run in O(n) complexity.
*/

// 排序求解
// O(nlogn)
int longestConsecutive_sort(vector<int> &num)
{
    int n = num.size();

    sort(num.begin(), num.end());
    int maxlen = 1, currlen = 1;

    for(int i = 1; i < n; ++i) {
        int diff = num[i] - num[i-1];
        if (diff == 0)
            continue;
        if (diff == 1) {
            ++currlen;
        }else {
            maxlen = max(currlen, maxlen);
            currlen = 1;
        }
    }
    maxlen = max(currlen, maxlen);

    return maxlen;
}

//动态规划求解
int longestConsecutive(vector<int> &num)
{

}


int main_()
{
    vector<int> num = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(num) << endl;
    return 0;
}
