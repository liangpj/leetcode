#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include<iostream>
#include<vector>
using std::vector;

template<typename T>
inline
void swap(vector<T> &arr, int i , int j)
{
    auto tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
}

template<typename T>
void quick_sort(vector<T> &arr, int beg, int last)
{

    if (beg >= last) return;
    int pivot = last;  //选定主元
    int i =  beg, j = last-1;
    while (i <= j) {
        while(arr[pivot] < arr[j]) --j;
        while(arr[i] < arr[pivot]) ++i;
        if (i <= j) {
            swap(arr, i, j);
            ++i; --j;
        }
    }
    swap(arr, i, pivot);

    quick_sort(arr, beg, i-1);
    quick_sort(arr, i+1, last);
}



template<typename T>
void quick_sort(vector<T> &arr)
{
    quick_sort(arr, 0, arr.size()-1);
}

#endif // QUICK_SORT_H

