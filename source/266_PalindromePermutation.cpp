#include "Utility.h"

// 266. Palindrome Permutation
// Level - Easy
// 
// Given a string, determine if a permutation of the string could form a palindrome.
// 
// Example 1:
// Input: "code"
// Output: false
// 
// Example 2:
// Input: "aab"
// Output: true
// 
// Example 3:
// Input: "carerac"
// Output: true

bool canPermutePalindrome(string s) {
    unordered_set<char> S;
    for (auto c : s)
    {
        if (S.find(c) != S.end()) S.erase(c);
        else S.insert(c);
    }

    return (S.size() < 2);
}

void test_canPermutePalindrome()
{
    VS tc = {"code", "aab", "carerac"};
    vector<bool> answers = {false, true, true};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (canPermutePalindrome(tc[i]) != answers[i]) ERROR_LOG;
    }
}
