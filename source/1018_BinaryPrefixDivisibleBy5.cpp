#include "Header.h"

// 1018. Binary Prefix Divisible By 5
// Level - Easy
// 
// Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)
// Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.
// 
// Example 1:
// Input: [0,1,1]
// Output: [true,false,false]
// Explanation:
// The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
// 
// Example 2:
// Input: [1,1,1]
// Output: [false,false,false]
// 
// Example 3:
// Input: [0,1,1,1,1,1]
// Output: [true,false,false,false,true,false]
// 
// Example 4:
// Input: [1,1,1,0,1]
// Output: [false,false,false,false,false]
// 
// Note:
// 1 <= A.length <= 30000
// A[i] is 0 or 1

vector<bool> prefixesDivBy5(vector<int>& A) {
    int len = A.size();
    vector<bool> result(len);

    int prev = 0;
    for (unsigned i = 0; i < len; ++i)
    {
        prev = (prev << 1) + A[i];
        prev = prev % 5;
        result[i] = (prev == 0);
    }
    return result;
}

void test_prefixesDivBy5()
{
    vector<vector<int>> tc = {{0,1,1}, {1,1,1}, {0,1,1,1,1,1}, {1,1,1,0,1}};
    vector<vector<bool>> answers = {{true,false,false}, {false,false,false}, {true,false,false,false,true,false}, {false,false,false,false,false}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (prefixesDivBy5(tc[i]) != answers[i]) ERROR_LOG;
    }
}
