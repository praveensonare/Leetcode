#include "Header.h"

// 1015. Smallest Integer Divisible by K
// Level - Medium
// 
// Given a positive integer K, you need to find the length of the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.
// Return the length of N. If there is no such N, return -1.
// Note: N may not fit in a 64-bit signed integer.
// 
// Example 1:
// Input: K = 1
// Output: 1
// Explanation: The smallest answer is N = 1, which has length 1.
// 
// Example 2:
// Input: K = 2
// Output: -1
// Explanation: There is no such positive integer N divisible by 2.
// 
// Example 3:
// Input: K = 3
// Output: 3
// Explanation: The smallest answer is N = 111, which has length 3.
// 
// Constraints:
// 1 <= K <= 105


int smallestRepunitDivByK(int K) {
    unordered_set<int> Set;
    int num = 1;
    int len = 1;

    while (Set.find(num) == Set.end())
    {
        Set.insert(num);
        num = num % K;
        if (num == 0) return len;

        ++len;
        num = num * 10 + 1;
    }
    return -1;
}

void test_smallestRepunitDivByK()
{
    vector<int> tc = {1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20};
    vector<int>answers = {1,-1, 3,-1,-1,-1,6,-1,9,-1,2,-1,6,-1,-1,-1,16,-1,18,-1};

    for (unsigned int i = 0; i < tc.size(); ++i)
    {
        if (smallestRepunitDivByK(tc[i]) != answers[i]) ERROR_LOG;
    }
}
