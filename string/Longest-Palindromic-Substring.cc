#include "../header.h"

/** Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
*/

static
bool isPalindrome(const string &s)
{
    int l = 0;
    int r = s.size()-1;
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

/*
暴力法求解，O(n^2)
*/
string longestPalindrome(string s)
{
    string res="";
    for(int i = 0; i < s.size(); ++i){
        for(int j = i+1; j <= s.size(); ++j) {
            string str = s.substr(i, j-i);
            if (isPalindrome(str)) {
                if (str.size() > res.size())
                    res = str;
            }
        }
    }
    return res;
}

class Solution {
private:
    int index =0;
    int maxlen =0;
private:
    void helper(const string &s, int l, int r) {
        while(l >=0 && r < s.size() && s[l] == s[r]) {
            --l; ++r;
        }
        if (maxlen < r-l-1) {
            index = l+1;
            maxlen = r-l-1;
        }
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        for (string::size_type i = 0; i < s.size()-1; ++i) {
            helper(s, i, i);
            helper(s, i, i+1);
        }
        return s.substr(index, maxlen);
    }
};

string longestPalindrome2(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}



//int main()
//{
//    string s = "ccd";
//    cout << longestPalindrome(s) << endl;
//
//    Solution res;
//    cout << res.longestPalindrome(s) << endl;
//    return 0;
//}
