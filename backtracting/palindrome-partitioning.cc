#include "../header.h"


/** Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/


/*
if the input is "aab", check if [0,0] "a" is palindrome. then check [0,1] "aa", then [0,2] "aab".
While checking [0,0], the rest of string is "ab", use ab as input to make a recursive call.
in this example, in the loop of i=l+1, a recursive call will be made with input = "ab".
Every time a recursive call is made, the position of l move right.

How to define a correct answer?
Think about DFS, if the current string to be checked (Palindrome) contains the last position,
in this case "c", this path is a correct answer, otherwise, it's a false answer.
https://discuss.leetcode.com/topic/6186/java-backtracking-solution/2
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        backtrack(s, 0, tmp, res);
        return res;
    }
private:
    bool isPalindrome(const string &s, int beg, int end)
    {
        int l = beg;
        int r = end-1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void backtrack(const string s, int start, vector<string> &tmp,
               vector<vector<string>> &res)
    {
        if (start == s.size()) {
            res.push_back(tmp);
        }else {
            for (int i = start+1; i <= s.size(); ++i) {
                if (isPalindrome(s, start, i)) {
                    tmp.push_back(s.substr(start, i-start));
                    backtrack(s, i, tmp, res);
                    tmp.pop_back();
                }
            }
        }
    }
};

//int main()
//{
//    string s = "aab";
//    auto res = partition(s);
//    for(auto e : res) {
//        for (auto s : e)
//            cout << s << " ";
//        cout << endl;
//    }
//    return 0;
//}
