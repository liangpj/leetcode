#include "../header.h"

/**Sqrt(x)

Implement int sqrt(int x).
Compute and return the square root of x.

*/


/*
使用牛顿迭代进行求解
*/
int mySqrt(int x)
{
    double x0 = 1, x1 = 0;
    while(1){
        x1 = x0 - (x0 * x0 - x)*1.0 / (2 * x0);
        if (abs(x1 - x0) <= 0.1)
            break;
        x0 = x1;
    }
    return (int)x1;
}

//使用二分法进行求解
int mySqrt_binSearch(int x)
{
    if (!x) return 0;
    int left = 0, right = INT_MAX;
    while(1) {
        int mid = left + (right - left)/ 2;
        if (mid > x/mid)
            right = mid - 1;
        else {
            if (mid+1 > x/(mid+1))
                return mid;
            left = mid + 1;
        }
    }
    return 0;
}

//int main()
//{
//    cout << (int)sqrt(2147395599) << endl;
//    cout << mySqrt(2147395599) << endl;
//    cout << mySqrt_binSearch(2147395599) << endl;
//    return 0;
//}
