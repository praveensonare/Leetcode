#include "Header.h"

#if 0
DECODE WAYS
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
Example 4:

Input: s = "1"
Output: 1

Input: s ="10"
Output: 1

Input: s ="111111111111111111111111111111111111111111111"
Output: 1836311903
#endif

class Solution {
public:
    Solution()
    {
        H.clear();
    }

    unordered_map<int, int> H;

    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;

        if (H.find(len) != H.end()) return H[len];

        string ts = s.substr(1);
        int ret = (s[0] == '0') ? 0 : (ts.empty()) ? 1 : numDecodings(ts);

        if (len > 1)
        {
            int num = 10 *(s[0] - '0') + s[1] - '0';
            if (num > 9 && num < 27)
            {
                ts =s.substr(2);
                ret += (ts.empty()) ? 1 : numDecodings(ts);
            }
        }
        H[len] = ret;
        return ret;
    }
};

