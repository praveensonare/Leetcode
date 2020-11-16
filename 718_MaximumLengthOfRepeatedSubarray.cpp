#include "Header.h"

// 718. Maximum Length of Repeated Subarray
// Level - Medium
// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
// 
// Example 1:
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation:
// The repeated subarray with maximum length is [3, 2, 1].
// 
// 
// Note:
// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100

int help(vector<int>& A, vector<int>& B)
{
    int lenA = A.size();
    int lenB = B.size();
    vector<int> dp(lenA, 0);
    int maxLen = 0;
    for (int b = 0; b < lenB; ++b)
    {
        for (int a = lenA - 1; a >= 0; --a)
        {
            if ((B[b] != A[a]))
            {
                dp[a] = 0;
                continue;
            }

            if (b == 0) dp[a] = 1;
            else dp[a] = (a == 0) ? 1 : dp[a - 1] + 1;

            maxLen = max(maxLen, dp[a]);
        }
    }
    return maxLen;
}

int findLength(vector<int>& A, vector<int>& B) {
    int lenA = A.size();
    int lenB = B.size();
    if (lenA == 0 || lenB == 0) return 0;

    if (lenB < lenA) return help(B, A);
    else return help(A,B);
}

void test_findLength()
{
    vector<pair<vector<int>, vector<int>>> tc = {pair<vector<int>,vector<int>>({1,2,3,2,1}, {3,2,1,4,7}),
                                                 pair<vector<int>,vector<int>>({0,0,0,0,0}, {0,0,0,0,0})};
    vector<int> answers = {3, 5};

    for (int idx = 0; idx < tc.size(); ++idx)
    {
        if (findLength(tc[idx].first, tc[idx].second) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
