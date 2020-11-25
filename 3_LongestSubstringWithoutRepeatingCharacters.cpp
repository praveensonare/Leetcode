#include "Header.h"

// 3. Longest Substring Without Repeating Characters
// Level - Medium
// 
// Given a string s, find the length of the longest substring without repeating characters.
// 
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// 
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// 
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// 
// Example 4:
// Input: s = ""
// Output: 0
// 
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

int lengthOfLongestSubstring(string s) {
    vector<int> ch(256,-1);
    int start = 0;
    int len = s.length();
    int ans = 0;

    for (int i = 0; i < len; ++i)
    {
        if (ch[s[i]] >= start)
        {
            ans = max(ans, i - start);
            start = ch[s[i]] + 1;
        }
        ch[s[i]] = i;
    }
    ans = max(ans, len - start);

    return ans;
}

void test_lengthOfLongestSubstring()
{
    vector<string> tc = {"abcabcbb", "bbbbb", "pwwkew", ""};
    vector<int> answers = {3,1,3,0};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (lengthOfLongestSubstring(tc[i]) != answers[i]) ERROR_LOG;
    }
}
