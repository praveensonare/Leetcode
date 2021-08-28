#include "Header.h"

// 845. Longest Mountain in Array
// Level - Medium
// 
// Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
// 
// B.length >= 3
// There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
// (Note that B could be any subarray of A, including the entire array A.)
// 
// Given an array A of integers, return the length of the longest mountain. 
// 
// Return 0 if there is no mountain.
// 
// Example 1:
// Input: [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
// 
// Example 2:
// Input: [2,2,2]
// Output: 0
// Explanation: There is no mountain.
// 
// Note:
// 
// 0 <= A.length <= 10000
// 0 <= A[i] <= 10000
// Follow up:
// 
// Can you solve it using only one pass?
// Can you solve it in O(1) space?
// 

int longestMountain(vector<int>& A) {
    int len = A.size();
    if (len < 3) return 0;

    vector<int> up(len, 1);
    vector<int> down(len, 1);
    for (int i = 1; i < len; ++i)
    {
        if (A[i] > A[i-1]) up[i] = up[i-1]+1; 
        if (A[len - 1 - i] > A[len - i]) down[len - 1 - i] = down[len - i] + 1;
    }

    int mlen = 0;
    for (int i = 0; i < len; ++i)
    {
        mlen = max(mlen, (up[i] == 1 || down[i] == 1) ? 0 : up[i]+down[i]-1);
    }
    return (mlen < 3) ? 0 : mlen;
}

void test_longestMountain()
{
    vector<vector<int>> tc = {{2,1,4,7,3,2,5}, {2,2,2}, {0,1,2,3,4,5,6,7,8,9}, {9,8,7,6,5,4,3,2,1,0}};
    vector<int> answers = {5, 0, 0, 0};

    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        if (longestMountain(tc[idx]) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}
