#include "Header.h"

// 526. Beautiful Arrangement
// Level - Medium
// 
// Suppose you have n integers from 1 to n. We define a beautiful arrangement as an array that is constructed by these n numbers successfully if one of the following is true for the ith position (1 <= i <= n) in this array:
// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
// Given an integer n, return the number of the beautiful arrangements that you can construct.
// 
// Example 1:
// Input: n = 2
// Output: 2
// Explanation:
// The first beautiful arrangement is [1, 2]:
// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
// The second beautiful arrangement is [2, 1]:
// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
// 
// Example 2:
// Input: n = 1
// Output: 1
// 
// Constraints:
// 1 <= n <= 15
// 

int countArrng = 0;
void help(int n, vector<bool>& visited, int pos)
{
    if (pos > n) ++countArrng;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i] && (i%pos == 0 || pos%i == 0))
        {
            visited[i] = true;
            help(n, visited, pos+1);
            visited[i] = false;
        }
    }
}

int countArrangement(int n) {
    countArrng = 0;
    vector<bool> visited(n+1,false);
    help(n, visited, 1);
    return countArrng;
}

void test_countArrangement()
{
    for (unsigned i = 1; i <= 2; ++i)
    {
        if (countArrangement(i) != (int)i) ERROR_LOG;
    }
}
