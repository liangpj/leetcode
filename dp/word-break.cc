#include "../header.h"

/** word break
Given a string s and a dictionary of words dict, add spaces in s to construct a
sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].
A solution is["cats and dog", "cat sand dog"].

*/


/*递归求解
Time Limit Exceeded
*/
bool wordBreak(string s, unordered_set<string> &dict)
{
    if (s=="" || dict.find(s) != dict.end())  return true;
    for(int i = 0; i < s.size(); ++i) {
        string word = s.substr(0,i);
        if (dict.find(word) != dict.end()
            && wordBreak(s.substr(i), dict))
            return true;
    }
    return false;
}

/*使用宽度优先搜索来进行求解
* 思路：把字符串中的index作为一个图的节点。
    判断是否有一条边能够从开始点到达结束点。其中节点之间表示一个word，
    word存在于dict之中
* Time Limit Exceeded
**/
bool wordBreak_bfs(const string s, unordered_set<string> &dict)
{
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = x+1; i <= s.size(); ++i){
            string word = s.substr(x, i-x);
            if (dict.count(word)) {
                if (i == s.size())
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}

//使用深度优先进行求解
// Time Limit Exceeded
bool wordBreak_dfs(const string &s, int x, unordered_set<string> &dict)
{
    for (int i = x+1; i <= s.size(); ++i) {
        string word= s.substr(x, i-x);
        if (dict.count(word)) {
            if (i == s.size())
                return true;
            if (wordBreak_dfs(s, i, dict))
                return true;
        }
    }
    return false;
}

bool wordBreak_dfs(const string s, unordered_set<string> &dict)
{
    return wordBreak_dfs(s, 0, dict);
}


/* DP 求解
以 s = "leetcode", dict = ["leet", "code"]为例
首先找到问题的状态：长度为i的字符串是可分的。
i = 0; s = "" --> dp(0) = true;

i = 1; s = "l" --> "" && "l" --> dp(0) && dict.find("l") = false;

i = 2; s = "le" --> "" && "le" or "l" && "e"
--> dp(0) && dict.find("le") or dp(1) && dict.find("e") = false;
因此，状态装换方程为：
dp(i) = dp(j) && dict.find(word), word = s[j:i]   0 =< j < i
*/
bool wordBreak_dp(const string &s, unordered_set<string> &dict)
{
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.count(s.substr(j, i-j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}


int wordbreak_main()
{
    unordered_set<string> dict = {"go","goal","goals","special"};
    string s= "goalspecial";

//    cout << (wordBreak(s, dict) ? "True" : "False") << endl;
    cout << "bfs: " << (wordBreak_bfs(s, dict) ? "true" : "false") << endl;
    cout << "dfs: " << (wordBreak_dfs(s, dict) ? "true" : "false") << endl;
    cout << "dp " << (wordBreak_dp(s, dict) ? "true" : "false") << endl;

    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
            aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict1 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa",
    "aaaaaaaaa","aaaaaaaaaa"};
    cout << (wordBreak_dp(s1, dict1) ? "True" : "False") << endl;

    unordered_set<string> dicts = {"leet", "code"};
    cout << "bfs " << (wordBreak_bfs("leetcode", dicts) ? "true" : "false") << endl;
    cout << "dfs " << (wordBreak_dfs("leetcode", dicts) ? "true" : "false") << endl;
    cout << "dp " << (wordBreak_dp("leetcode", dicts) ? "true" : "false") << endl;


    return 0;
}
