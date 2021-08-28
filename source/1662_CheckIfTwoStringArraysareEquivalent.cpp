#include "Utility.h"

// 1662. Check If Two String Arrays are Equivalent
// Level - Easy
// 
// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
// A string is represented by an array if the array elements concatenated in order forms the string.
// 
// Example 1:
// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.
// 
// Example 2:
// Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
// Output: false
// 
// Example 3:
// Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
// Output: true
// 
// Constraints:
// 1 <= word1.length, word2.length <= 103
// 1 <= word1[i].length, word2[i].length <= 103
// 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
// word1[i] and word2[i] consist of lowercase letters.

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    unsigned len1 = word1.size();
    unsigned len2 = word2.size();
    unsigned x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    auto getNextWord = [](unsigned& y, unsigned&x, const string& w)
    {
        char c = w[x++];
        if (x == w.size())
        {
            x = 0;
            ++y;
        }
        return c;
    };
    while(y1 != len1 && y2 != len2)
    {
        if (getNextWord(y1, x1, word1[y1]) != getNextWord(y2, x2, word2[y2])) return false;
    }
    return (y1 == len1 && y2 == len2);
}

#define PAIR pair<vector<string>,vector<string>>
void test_arrayStringsAreEqual()
{
    vector<PAIR> tc = { PAIR({"ab", "c"},{"a", "bc"}),
                        PAIR({"a", "cb"},{"ab", "c"}),
                        PAIR({"abc", "d", "defg"},{"abcddefg"}),
                        PAIR({"abc", "d", "defg"},{"abcddef"})};
    vector<bool> answers = {true, false, true, false};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (arrayStringsAreEqual(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
