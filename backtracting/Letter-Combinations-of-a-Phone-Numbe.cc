#include "../header.h"

/**Letter Combinations of a Phone Numbe
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

static
void letterBT(vector<string> &letter, const string &digits,
              int start, string s, vector<string> &res)
{
    if (start == digits.size()) {
        res.push_back(s);
        return ;
    }

    int dig = int(digits[start] - '0');
    for (int i = 0; dig < letter.size() && i < letter[dig].size(); ++i)
        letterBT(letter, digits, start+1,s+letter[dig][i], res);
}

vector<string> letterCombinations(string digits)
{
    if (digits == "") return {};
    vector<string> letter = {{" "}, {"O_O"}, {"abc"}, {"def"},
            {"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    vector<string> res;
    string s = "";
    letterBT(letter, digits, 0, s, res);
    return res;

}


//int main()
//{
//    string digits = "23";
//    auto res = letterCombinations(digits);
//    for (auto s : res)
//        cout << s << endl;
//    return 0;
//}
