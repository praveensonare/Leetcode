#include "Utility.h"

// 454. 4Sum II
// Level - Medium
// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
// To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
// 
// Example:
// Input:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
// Output:
// 2
// 
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

    unordered_map<int, int> H;
    H.clear();
    int count = 0;
    for (auto a: A) for (auto b : B) ++H[a + b];
    for (auto c: C) for (auto d : D) if (H.find(-(c + d)) != H.end()) count += H.find(-(c + d))->second;

    return count;
}

void test_fourSumCount()
{
    vector<vector<vector<int>>> tc = {{{0,0},{0,0},{0,0},{0,0}}, {{1,2},{-2,-1},{-1,2},{0,2}}};
    VI answers = {16, 2};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (fourSumCount(tc[i][0], tc[i][1], tc[i][2], tc[i][3]) != answers[i]) ERROR_LOG;
    }
}
