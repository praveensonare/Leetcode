#include "Utility.h"
// 1247. Minimum Swaps to Make Strings Equal
// Level - Medium
// 
// You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].
// Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.
// 
// Example 1:
// Input: s1 = "xx", s2 = "yy"
// Output: 1
// Explanation:
// Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
// 
// Example 2:
// Input: s1 = "xy", s2 = "yx"
// Output: 2
// Explanation:
// Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
// Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
// Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
// 
// Example 3:
// Input: s1 = "xx", s2 = "xy"
// Output: -1
// 
// Example 4:
// Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
// Output: 4
// 
// Constraints:
// 1 <= s1.length, s2.length <= 1000
// s1, s2 only contain 'x' or 'y'.

int minimumSwap(string s1, string s2) {
    unsigned len = s1.length();
    if (len != s2.length()) return -1;

    int xy = 0, yx = 0;
    int swap;
    for (unsigned i = 0; i < len; ++i)
    {
        if (s1[i] == s2[i]) continue;

        if (s1[i] == 'x') ++xy;
        else ++yx;
    }

    return ((xy+yx)%2 != 0) ? -1 : (xy/2) + (yx/2) + xy%2 +yx%2;

}

void test_minimumSwap()
{
    vector<PAIR_SS> tc = {PAIR_SS("xx","yy"),
        PAIR_SS("xy","yx"),
        PAIR_SS("xx","xy"),
        PAIR_SS("xxyyxyxyxx","xyyxyxxxyx")};
    vector<int> answers = {1,2,-1,4};

    for (unsigned i = 0 ; i < tc.size(); ++i)
    {
        if (minimumSwap(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }

}
