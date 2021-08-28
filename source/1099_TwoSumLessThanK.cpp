#include "Header.h"
#if 0
1099. Two Sum Less Than K
Level - Easy

Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.

Example 1:
Input: A = [34,23,1,24,75,33,54,8], K = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: A = [10,20,30], K = 15
Output: -1
Explanation: In this case it is not possible to get a pair sum less that 15.

#endif

int twoSumLessThanK(vector<int>& A, int K)
{
    sort(A.begin(), A.end());
    int start = 0;
    int end = A.size() - 1;
    int sum = 0;
    int ans = -1;

    while(start < end)
    {
        sum = A[start] + A[end];
        if (sum < K)
        {
            ans = max(ans, sum);
            ++start;
        }
        else
        {
            --end;
        }
    }
    return ans;
}
