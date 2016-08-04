#include "../header.h"

#include<sstream>

/***
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

int strToInt( string str)
{
    istringstream is(str);
    int number;
    is >> number;
    return number;
}

int evalRPN1(vector<string> &tokens) {
    stack<int> st;
    int a, b;
    string tok;
    for (const auto tok : tokens) {
        if (tok.find_first_of("0123456789") != string::npos)
            ///st.push(stoi(tok));
            st.push(strToInt(tok));
        else {
            b = st.top(); st.pop();
            a = st.top(); st.pop();
            if (tok == "+" )
                st.push(a + b);
            else if (tok =="-" )
                st.push(a-b);
            else if (tok == "*" )
                st.push(a*b);
            else if (tok == "/" )
                st.push(a/b);
        }
    }
    return st.top();
}

void evaluate_reverse_polish_notation()
{
    //["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    //["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << evalRPN1(tokens1) << endl;
    cout << evalRPN1(tokens2) << endl;

}

