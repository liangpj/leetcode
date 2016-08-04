#include "../header.h"

/**Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        vector<int> subset;
        backtrack(nums, 0, subset, solution);
        return solution;
    }
private:
    void backtrack(vector<int> &nums, int start, vector<int> &subset, vector<vector<int>> &solution) {
        solution.push_back(subset);
        int prevNum = INT_MAX;
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] != prevNum) {
                prevNum = nums[i];
                subset.push_back(nums[i]);
                backtrack(nums, i+1, subset, solution);
                subset.pop_back();
            }
        }
    }
};
