#include "Header.h"

// 159. Longest Substring with At Most Two Distinct Characters
// Level - Medium
// Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
// 
// Example 1:
// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// 
// Example 2:
// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.

int lengthOfLongestSubstringTwoDistinct(string s) {
    pair<char, pair<int, int>> start(' ', pair<int,int>(0,0));
    pair<char, pair<int, int>> end(' ', pair<int,int>(0,0));
    pair<char, pair<int, int>> temp(' ', pair<int,int>(0,0));

    int len = s.length();
    int maxLen = 0;
    int st = 0;
    for (int i = 0; i < len; ++i)
    {
        if (start.first == ' ')
        {
            start = pair<char, pair<int,int>>(s[i], pair<int,int>(i,i));
        }
        else if (s[i] == start.first)
        {
            if (end.first == ' ') start.second.second = i;
            else
            {
                temp = start;
                start = end;
                end = temp;
                end.second.second = i;
            }
        }
        else if (end.first == ' ')
        {
            end = pair<char, pair<int,int>>(s[i], pair<int,int>(i,i));
        }
        else if (s[i] == end.first)
        {
            end.second.second = i;
        }
        else
        {
            maxLen = max(maxLen, i - st);
            st = start.second.second + 1;
            end.second.first = start.second.second + 1;
            start = end;
            end = pair<char, pair<int,int>>(s[i], pair<int,int>(i,i));

        }
    }

    maxLen = max(maxLen, len - st);
    return maxLen;
}

void test_lengthOfLongestSubstringTwoDistinct() //159. Longest Substring with At Most Two Distinct Characters
{
    vector<string> tc = {"aac", "eceba", "ccaabbb", "", "qqqq", "qwqwqwqwqwqwqwqwqw"};
    vector<int> answers = {3,3,5,0,4,18};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (lengthOfLongestSubstringTwoDistinct(tc[i]) != answers[i]) ERROR_LOG;
    }
}
