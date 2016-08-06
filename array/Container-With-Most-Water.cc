#include "../header.h"

/**Container With Most Water
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together
with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

inline
int getArea(int i, int yi, int j, int yj)
{
    int x = yi < yj ? yi : yj;
    return (j - i)*x;
}


/*
暴力法：O(n^2)
*/
int maxArea(vector<int>& height)
{
    int currmax = 0;
    for (int i = 0; i < height.size()-1; ++i){
        for (int j = i+1; j < height.size(); ++j){
            currmax = max(currmax, getArea(i, height[i], j, height[j]));
        }
    }
    return currmax;
}

//int main()
//{
//    vector<int> height = {1,1};
//    cout << maxArea(height) << endl;
//
//    return 0;
//}
