#include "../header.h"

/**Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*使用两个指针i和j，用来记录当前最大substring的最大的index。
其中使用map用来保存每个字符出现的位置。其中i用来遍历字符串，
而j用来记录当前子串的起始位置。当当前字符在前面已经出现过时更新j
note: 我们可以使用map来存储每个字符出现的位置。
但是由于char也可以使用int来表示。并且最大取值为255，所以也可以使用
vector来进行存储，加快速度。
*/
int lengthOfLongestSubstring(string s)
{
    int longest = 0;
//    map<char, int> dict;
    vector<int> ivec(256, -1);
    for (int i = 0, j = 0; i < s.size(); ++i) {
        //说明该字符已经存在s中
//        if (dict.find(s[i]) != dict.end()) {
//            //更新j
//            j = max(j, dict[s[i]] + 1);
//        }
        if (ivec[s[i]] != -1) {
            j = max(j, ivec[s[i]]+1);
        }
//        dict[s[i]] = i; //记录当前字符出现的位置
        ivec[s[i]] = i;
        longest = max(longest, i-j+1);
    }
    return longest;
}

//int main()
//{
//    string s = "abcabcbb";
//    cout << lengthOfLongestSubstring(s) << endl;
//
//    return 0;
//}
