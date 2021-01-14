#include "Utility.h"

// 567. Permutation in String
// Level - Medium
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
// 
// Example 1:
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// 
// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
// 
// Constraints:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

bool checkInclusion(string s1, string s2) {

    int l1 = s1.length();
    int l2 = s2.length();
    if (l1 > l2) return false;

    unordered_map<char, int> H1;
    for (auto c : s1) H1[c]++;

    int mismatch = l1;

    unordered_map<char, int> H2;
    for (int i = 0; i < l1; ++i)
    {
        if (H1.find(s2[i]) != H1.end() && H2[s2[i]] < H1[s2[i]])
        {
            --mismatch;
        }
        H2[s2[i]]++;
    }

    if (mismatch == 0) return true;

    for (int i = l1; i < l2; ++i)
    {
        if (H1.find(s2[i]) != H1.end())
        {
            if (H2[s2[i]] < H1[s2[i]]) --mismatch;
        }
        H2[s2[i]]++;

        if (H1.find(s2[i-l1]) != H1.end())
        {
            if (H2[s2[i-l1]] <= H1[s2[i-l1]]) ++mismatch;
        }

        H2[s2[i-l1]]--;

        if (mismatch == 0) return true;
    }

    return false;
}

void test_checkInclusion()
{
    vector<PAIR_SS> tc = { PAIR_SS("ab","aadboaoo"),
        PAIR_SS("ab","eidbaooo"),
        PAIR_SS("asdasd","asd"),
        PAIR_SS("ab","eidboaoo")};
    vector<bool> answers = {false, true, false, false};

    for (unsigned i = 0; i <tc.size(); ++i)
    {
        if (checkInclusion(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }

}
