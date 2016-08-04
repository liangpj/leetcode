#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

#include <vector>
using std::vector;

/** 分治法的思想
* 将原问题分解为几个规模较小但是类似原问题的子问题，
* 递归的求解这些子问题，然后在合并这些子问题的解来
* 建立原问题的解
**
***分治模式
**分解：将问题分解为若干子问题，这些子问题是原问题的规模较小的实例
**解决：递归的求解各子问题
**合并：合并这些子问题的解成原问题的解
*/

/**合并函数
*arr是一个数组，p,q和r是数组的下标 (p<=q<r)
*arr[p..q]和arr[q+1..r]都已经排好序，合并这两个子数组，形成一个排序好的数组
*/

template<typename T>
static
void _merge(vector<T> &arr, int p, int q, int r)
{
    vector<T> left(arr.begin()+p, arr.begin()+q+1);
    vector<T> right(arr.begin()+q+1, arr.begin()+r+1);
    int k = p, i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < left.size())
        arr[k++] = left[i++];
    while (j < right.size())
        arr[k++] = right[j++];
}

template<typename T>
void merge_sort(vector<T> &arr, int beg, int last)
{
    if (beg < last) {
        int mid = beg + (last - beg) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, last);
        _merge(arr, beg, mid, last);
    }
}

/**归并排序
归并排序是典型的分治算法的思想
*/

/* 归并步骤：
对于数组arr, [p, q], arr[q+1,r]已经排好序
现在使得arr[p,r]有序
*/
template<typename T>
void merge_sort(vector<T> &arr)
{
    merge_sort(arr, 0, arr.size()-1);
}

#endif // __MERGE_SORT_H


