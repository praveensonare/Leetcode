#include "Header.h"

// 340. Longest Substring with At Most K Distinct Characters
// Level - Medium
// 
// Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
// 
// Example 1:
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: The substring is "ece" with length 3.
// 
// Example 2:
// Input: s = "aa", k = 1
// Output: 2
// Explanation: The substring is "aa" with length 2.
// 
// Constraints:
// 1 <= s.length <= 5 * 104
// 0 <= k <= 50

int lengthOfLongestSubstringKDistinct(string s, int k) {

    int len = s.length();
    if (len * k == 0) return 0;

    unordered_map<char, int> H;
    int max_size = 0;

    int left = 0;
    for (int i = 0; i < len; ++i)
    {
        if (H.size() >= (unsigned)k && H.find(s[i]) == H.end())
        {
            max_size = max(max_size, i - left);

            for ( ; left < len; ++left)
            {
                if (left == H[s[left]])
                {
                    H.erase(s[left]);
                    ++left;
                    break;
                }
            }
        }
        H[s[i]] = i;
    }
    max_size = max(max_size, len - left);

    return max_size;
}

void test_lengthOfLongestSubstringKDistinct()
{
    vector<PAIR_SI> tc = {PAIR_SI("aba", 1),
        PAIR_SI("eceba", 2),
        PAIR_SI("aa", 1),
        PAIR_SI("aaabbaaccccdd", 3),
        PAIR_SI("aa", 0)};
    vector<int> answer = {1, 3, 2, 11, 0};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (lengthOfLongestSubstringKDistinct(tc[i].first, tc[i].second) != answer[i]) ERROR_LOG;
    }
}
