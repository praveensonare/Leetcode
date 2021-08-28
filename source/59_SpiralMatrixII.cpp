#include "Header.h"

// 59. Spiral Matrix II
// Level - Medium
// 
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
// Example 1:
// Input: n = 3
// 1 2 3
// 8 9 4
// 7 6 5
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// 
// Example 2:
// Input: n = 1
// Output: [[1]]
// 
// 
// Constraints:
// 1 <= n <= 20

vector<vector<int>> generateMatrix(int n) {
    int layer = 0;
    int x,y;
    int num = 1;
    vector<vector<int>> result(n, vector<int>(n));
    while(layer <= n/2)
    {
        x = y = layer;
        //left->right
        for (x = layer; x < n-layer; ++x) result[y][x] = num++;

        // top ->bottom
        --x;
        for (y = layer+1; y < n-layer; ++y) result[y][x] = num++;

        // right->left
        --y;
        --x;
        for ( ; x >= layer; --x) result[y][x] = num++;

        //bottom->top
        ++x;
        --y;
        for ( ; y > layer; --y) result[y][x] = num++;

        ++layer;
    }
    return result;
}

void test_generateMatrix()
{
    vector<int> tc = {3, 1, 4};
    vector<vector<vector<int>>> answers = {{{1,2,3},{8,9,4},{7,6,5}},
                                           {{1}},
                                          {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (generateMatrix(tc[i]) != answers[i]) ERROR_LOG;
    }
}
