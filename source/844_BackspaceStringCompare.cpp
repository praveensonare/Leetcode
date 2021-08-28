#include "Header.h"

// 844. Backspace String Compare
// Level - Easy
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.
// 
// Example 1:
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// 
// Example 2:
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// 
// Example 3:
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// 
// Example 4:
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// 
// Note:
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// 
// Follow up:
// Can you solve it in O(N) time and O(1) space?

string decodeString(string& s)
{
    string result = "";
    for ( auto c : s)
    {
        if (c == '#')
        {
            if (result.empty()) continue;
            result.pop_back();
        }
        else result.push_back(c);
    }
    return result;
}

bool backspaceCompare(string S, string T) {
    const string s1 = decodeString(S);
    const string s2 = decodeString(T);
    return (s1 == s2);
}

void test_backspaceCompare()
{

}
