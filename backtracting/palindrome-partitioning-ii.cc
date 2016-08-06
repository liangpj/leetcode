#include "../header.h"

/** Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
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

/*超时
*/
int minCut(string s)
{
    if (isPalindrome(s)) return 0;

    int n = s.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= s.size(); ++i) {
        string ss = s.substr(0, i);
        for (int j = 0; j < ss.size(); ++j) {
            if (j == 0 && isPalindrome(ss)) {
                dp[i] = 0;
                break;
            }else if (isPalindrome(ss.substr(j, ss.size()))) {
                dp[i] = min(dp[i], 1+dp[j]);
            }
        }
    }

    return dp[n];
}

//int main()
//{
//    string s = "aab";
//    cout << minCut(s) << endl;
//
//    return 0;
//}
