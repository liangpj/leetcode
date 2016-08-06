#include "../header.h"

/**Generate Parentheses
Given n pairs of parentheses, write a function to
generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

static
void generateParent(int left, int right, int n, string &s, vector<string> &res)
{
    if (s.size() == 2*n) {
        res.push_back(s);
        return;
    }

    if (left < n) {
        s.push_back('(');
        ++left;
        generateParent(left, right, n, s, res);
        --left;
        s.erase(s.size()-1);
    }
    if(right < left && left > 0) {
        s.push_back(')');
        ++right;
        generateParent(left, right, n, s, res);
        s.erase(s.size()-1);
        --right;
    }

}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string s;
    generateParent(0, 0, n, s, res);
    return res;
}

//int main()
//{
//    auto res = generateParenthesis(3);
//    return 0;
//}
