#include "../header.h"

/** Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}"
are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> pare{{')', '('}, {'}', '{'}, {']', '['}};

        if(s.size() < 2)
            return false;

        for(int i = 0; i != s.size(); ++i) {
            switch(s[i]) {
                case '(' :
                case '{' :
                case '[' :
                    st.push(s[i]);
                    break;
            }

            if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(!st.empty()) {
                    if(st.top() == pare[s[i]])
                        st.pop();
                    else
                        return false;
                } else
                    return false;
            }
        }

        return st.empty();
    }
};
