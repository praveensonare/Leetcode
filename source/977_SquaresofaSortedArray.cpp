#include "Header.h"

// 977. Squares of a Sorted Array
// Level: Easy
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// 
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// 
// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
// 
// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.
// 
// Note: Do it in a single pass.

vector<int> sortedSquares(vector<int>& A) {
    int len = A.size();
    int firstPositive = 0;
    for (; firstPositive < len; ++firstPositive)
    {
        if (A[firstPositive] >= 0) break;
    }

    int start = 0;
    int end = len - 1;
    int pos = end;
    vector<int>result(len);
    while((start < firstPositive || end >= firstPositive) && pos >=0)
    {
        if (abs(A[end]) >= abs(A[start]))
        {
            result[pos--] = A[end] * A[end];
            --end;
        }
        else
        {
            result[pos--] = A[start] * A[start];
            ++start;
        }
    }
    return result;
}

void test_sortedSquares()
{
    vector<vector<int>> tc = {{-4,-1,0,3,10}, {-7,-3,2,3,11},  {-1}};
    vector<vector<int>> answers = {{0,1,9,16,100}, {4,9,9,49,121}, {1}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (sortedSquares(tc[i]) != answers[i]) ERROR_LOG;
    }

}
