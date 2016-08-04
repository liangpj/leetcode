
#include "../header.h"

/** single-number

Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
*/

int singleNumber(int A[], int n) {
    int x = 0;
    for (int i = 0; i < n; ++i)
        x ^= A[i];
    return x;

}

int single_Number_main()
{
    int a = 2, b = 2, c = 3;
    cout << (a ^ b ^ c) << endl;
    int A[] = {1,1,2,2,3,3,4,6,6,7,7};
    cout << singleNumber(A, 11) << endl;

    return 0;
}
