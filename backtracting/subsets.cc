#include "../header.h"

/**subsets
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> subset;
        backtrack(nums, 0, subset, solution);
        return solution;
    }
private:
    void backtrack(vector<int> &nums, int start, vector<int> &subset, vector<vector<int>> &solution) {
        solution.push_back(subset);
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset, solution);
            subset.pop_back();
        }
    }
};

