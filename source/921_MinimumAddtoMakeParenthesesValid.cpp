#include "Utility.h"

// 921. Minimum Add to Make Parentheses Valid
// Level - Medium
// 
// Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
// 
// Formally, a parentheses string is valid if and only if:
// It is the empty string, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
// 
// Example 1:
// Input: "())"
// Output: 1
// 
// Example 2:
// Input: "((("
// Output: 3
// 
// Example 3:
// Input: "()"
// Output: 0
// 
// Example 4:
// Input: "()))(("
// Output: 4
// 
// Note:
// S.length <= 1000
// S only consists of '(' and ')' characters.


int minAddToMakeValid(string S) {
    stack<char> st;
    int invalid = 0;

    for (auto c : S)
    {
        if (c == '(') st.push(c);
        else
        {
            if (st.empty()) ++invalid;
            else
            {
                st.pop();
            }
        }
    }

    return invalid + st.size();
}

void test_minAddToMakeValid()
{
    VS tc = {"())", "(((", "()", "()))(("};
    VI answers = {1,3,0,4};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (minAddToMakeValid(tc[i]) != answers[i]) ERROR_LOG;
    }
}

