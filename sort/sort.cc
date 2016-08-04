#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<random>

#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

int sort()
{
    uniform_int_distribution<int> random(-1000,1000);
    vector<int> arr;
    default_random_engine e;
    for (int i = 0; i < 1000000; ++i)
        arr.push_back(random(e));

    vector<int> aa(arr);
//    merge_sort(arr);
    quick_sort(arr);
    sort(aa.begin(), aa.end());

    cout << equal(arr.begin(), arr.end(), aa.begin()) << endl;


    return 0;
}
