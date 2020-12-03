#include "Header.h"

// 779. K-th Symbol in Grammar
// Level -Medium
// On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
// Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).
// 
// Examples:
// Input: N = 1, K = 1
// Output: 0
// 
// Input: N = 2, K = 1
// Output: 0
// 
// Input: N = 2, K = 2
// Output: 1
// 
// Input: N = 4, K = 5
// Output: 1
// Explanation:
// row 1: 0
// row 2: 01
// row 3: 0110
// row 4: 01101001
// 
// Note:
// N will be an integer in the range [1, 30].
// K will be an integer in the range [1, 2^(N-1)].


int kthGrammar(int N, int K) {
    //int len = N.size();
    int ans = 0;
    while (K > 1)
    {
        if (K % 2 == 0) ans = (ans ^ 1) & 1;
        K = (K+1)/2;

    }
    return (ans == 0) ? 0 : 1;
}

void test_kthGrammar()          // 779. K-th Symbol in Grammar
{
    vector<vector<int>> tc = {{1,1}, {2,1}, {2,2}, {4,5}, {29,54}};
    vector<int> answers = {0,0,1,1,0};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (kthGrammar(tc[i][0], tc[i][1]) != answers[i]) ERROR_LOG;
    }
}
