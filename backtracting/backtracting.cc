#include<iostream>
#include<string>
#include<vector>


using namespace std;


int solution[5];
bool use[5] = {false};

void backtrack(int n) {
    if (n == 5) {
        //processing solution
        for(int i = 0; i < n; ++i)
            cout << solution[i] << " ";
        cout << endl;
        return;
    } else
    {
        for (int i = 0; i < 5; ++i) {
            if (!use[i]) {
                use[i] = true;
                solution[n] = i;
                backtrack(n+1);
                use[i] = false;
            }
        }
    }
}

void backtrackabc(const vector<char> &num, vector<bool> use,
                  vector<char> solution)
{
    if (solution.size() == 3) {
        for(const auto e : solution)
            cout << e << " ";
        cout << endl;
        return;
    }else {
        for(int i = 0; i < num.size(); ++i) {
            if (!use[i]) {
                use[i] = true;
                solution.push_back(num[i]);
                backtrackabc(num, use, solution);
                solution.pop_back();
                use[i] = false;
            }
        }
    }
}


void backtrackabb(const vector<char> &num, vector<bool> use,
                  vector<char> solution)
{
    if (solution.size() == 3) {
        for(const auto e : solution)
            cout << e << " ";
        cout << endl;
        return;
    }else {
        char prevChar = '\0';
        for(int i = 0; i < num.size(); ++i) {
            if (!use[i] && prevChar != num[i]) {
                prevChar = num[i];
                use[i] = true;
                solution.push_back(num[i]);
                backtrackabb(num, use, solution);
                solution.pop_back();
                use[i] = false;
            }
        }
    }
}


void backtracksubsets(vector<int> &nums, int start,
                      vector<int> &subset, vector<vector<int>> &solution)
{
    //因为当前每个子集都是一个解，因此不需要判断
    solution.push_back(subset);
    int prevNum = INT_MAX;
    //当前所有可以取值的情况
    for (int i = start; i < nums.size(); ++i) {
        if (prevNum != nums[i]) {
        prevNum = nums[i];
        subset.push_back(nums[i]);
        backtracksubsets(nums, i+1, subset, solution); //进入下一个
        subset.pop_back();
        }
    }
}

//int main()
//{
////    backtrack(0);
////    vector<char> nums = {'a', 'b', 'b'};
////    vector<char> solution;
////    vector<bool> use(3, false);
////    backtrackabc(nums, use, solution);
////    cout << "----------------" << endl;
////    backtrackabb(nums, use, solution);
//
//    vector<int> nums = {1,2,2};
//    vector<int> subset;
//    vector<vector<int>> solution;
//    backtracksubsets(nums, 0, subset, solution);
//    for(auto e : solution)
//    {
//        for (auto i : e)
//            cout << i << " ";
//        cout << endl;
//    }
//    cout << solution.size() << endl;
//    return 0;
//}

