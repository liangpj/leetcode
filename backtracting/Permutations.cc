#include "../header.h"

/**Permutations
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp(nums.size(), 0);
        vector<bool> use(nums.size(), false);
        helper(nums, 0, use, tmp, res);
        return res;
    }
private:
    void helper(vector<int> &nums, int start, vector<bool> &use,
                vector<int> &tmp, vector<vector<int>> &res)
    {
        if (start == nums.size()) {
            res.push_back(tmp);
            return ;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!use[i]) {
                use[i] = true;
                tmp[start] = nums[i];
                helper(nums, start+1, use, tmp, res);
                use[i] = false;
            }
        }
    }
};

//int main()
//{
//    Solution s;
//    vector<int> nums = {1,2,3};
//    auto res = s.permute(nums);
//    for (auto e : res) {
//        for (auto i : e)
//            cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}
