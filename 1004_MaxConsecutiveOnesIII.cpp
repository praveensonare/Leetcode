#include "Header.h"

// 1004. Max Consecutive Ones III
// Level - Medium
// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
// Return the length of the longest (contiguous) subarray that contains only 1s.
// 
// Example 1:
// Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
// Output: 6
// Explanation:
// [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
// 
// Example 2:
// Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
// Output: 10
// Explanation:
// [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
// 
// Note:
// 1 <= A.length <= 20000
// 0 <= K <= A.length
// A[i] is 0 or 1

int longestOnes(vector<int>& A, int K) {
    // sliding window
    int start = -1;
    int end = 0;
    int mx = 0;
    int zcount = 0;
    int len = A.size();
    for (int i = 0; i < len; ++i)
    {

        if (A[i] == 1) continue;

        if (zcount < K)
        {
            ++zcount;
            mx = i + 1;
        }
        else
        {
            mx = max(mx, i-1-start);
            while(A[++start] != 0);
        }
    }

    return (A.back() == 1) ? max(mx, len -1 - start) : mx;
}

#define V vector<int>
#define PAIR pair<V,int>
void test_longestOnes()
{
    vector<PAIR> tc = {PAIR(V({1,1,1,0,0,0,1,1,1,1,0}), 2), PAIR(V({1,0,1,0,1,1,1,1}),2), PAIR(V({0,0,0,1}), 4), PAIR(V({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}),3)};
    vector<int> answers = {6,8,4,10};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (longestOnes(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
