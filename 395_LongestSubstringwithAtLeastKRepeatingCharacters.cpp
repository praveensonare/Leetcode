#include "Header.h"

// 395. Longest Substring with At Least K Repeating Characters
// Level - Medium
// 
// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
// 
// Example 1:
// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// 
// Example 2:
// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
// 
// 
// Constraints:
// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105

int longestSubstring(string s, int k) {
    int len = s.length();
    if (len < k) return 0;

    vector<vector<int>> H(26);
    for (int i = 0; i < len; ++i) H[s[i] - 'a'].push_back(i);

    for (int i = 0; i < 26; ++i)
    {
        if (H[i].size() < (unsigned)k) for (auto n : H[i]) s[n] = '.';
    }

    int start = 0;
    size_t found = s.find_first_of(".");
    if (found == string::npos) return len;

    int msize = 0;
    while(found != string::npos)
    {
        found = s.find_first_of(".", start);
        msize = max(msize, longestSubstring(s.substr(start, found - start), k));
        start = found + 1;
    }

    return msize;
}

void test_longestSubstring()
{
    vector<pair<string, int>> tc = {pair<string, int>("bbaaacbd",3), pair<string, int>("ababacb",3), pair<string, int>("weitong",2), pair<string, int>("aaabb",3), pair<string, int>("ababbc",2)};
    vector<int> answers = {3,0,0,3,5};

    for (unsigned i = 0; i < 1; ++i)
    {
        if (longestSubstring(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
