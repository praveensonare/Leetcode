#include "Header.h"

// 1492. The kth Factor of n
// Level - Medium
// 
// Given two positive integers n and k.
// A factor of an integer n is defined as an integer i where n % i == 0.
// Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
// 
// Example 1:
// Input: n = 12, k = 3
// Output: 3
// Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
// 
// Example 2:
// Input: n = 7, k = 2
// Output: 7
// Explanation: Factors list is [1, 7], the 2nd factor is 7.
// 
// Example 3:
// Input: n = 4, k = 4
// Output: -1
// Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
// 
// Example 4:
// Input: n = 1, k = 1
// Output: 1
// Explanation: Factors list is [1], the 1st factor is 1.
// 
// Example 5:
// Input: n = 1000, k = 3
// Output: 4
// Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
// 
// Constraints:
// 1 <= k <= n <= 1000

int kthFactor(int n, int k) {
    int sq = sqrt(n);
    stack<int> st;
    for (int i = 1; i <= sq; ++i)
    {
        if (n % i == 0)
        {
            st.push(n / i);
            --k;
            if (k == 0) return i;
        }
    }
    if (sq*sq == n) ++k;
    while(!st.empty())
    {
        --k;
        if (k == 0) return st.top();
        st.pop();
    }
    return -1;
}

void test_kthFactor()
{
    vector<vector<int>> tc = {{7,2}, {12,3}, {4,1}, {4,2}, {4,3}};
    vector<int> answers = {7, 3, 1, 2, 4};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (kthFactor(tc[i][0], tc[i][1]) != answers[i]) ERROR_LOG;
    }
}
