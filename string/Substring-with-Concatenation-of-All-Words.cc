#include "../header.h"

/**Substring with Concatenation of All Words
You are given a string, s, and a list of words, words,
that are all of the same length. Find all starting indices of
substring(s) in s that is a concatenation of each word in words
 exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
蛮力法
*/
vector<int> findSubstring(string s, vector<string>& words) {

    vector<int> res;
    unordered_map<string,int> counts;
    for(auto w : words)
        counts[w]++;

    int wordlen = words[0].size();
    int nword = words.size();
    int i = 0, n = s.size();

    while (i <= n-nword*wordlen) {
        unordered_map<string, int> visit;
        int j = 0;
        for (; j < nword; ++j) {
            string w = s.substr(i + j*wordlen, wordlen);
            if (counts.find(w) != counts.end()){ //该word存在
                visit[w]++;
                if (visit[w] > counts[w]) break;
            }else
                break;
        }
        if (j == nword)
            res.push_back(i);
        ++i;
    }
    return res;
}

//int main()
//{
//    string s = "barfoofoobarthefoobarman";
//    vector<string> words = {"bar","foo","the"};
//    auto res = findSubstring(s, words);
//    for (auto i : res)
//        cout << i << " ";
//    cout << endl;
//
//    return 0;
//}
