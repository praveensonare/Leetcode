#include "Header.h"

// 54. Spiral Matrix
// Level - Medium
// 
// Given an m x n matrix, return all elements of the matrix in spiral order.
// 
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// 
// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int layer = 0;
    int x,y;
    int W = matrix[0].size();
    int H = matrix.size();
    vector<int> result(W * H);

    int n = min(W, H);
    unsigned pos = 0;
    while(layer <= n/2)
    {
        x = y = layer;
        //left->right
        for (x = layer; x < W-layer; ++x) if (pos < result.size()) result[pos++] = matrix[y][x];

        // top ->bottom
        --x;
        for (y = layer+1; y < H-layer; ++y) if (pos < result.size()) result[pos++] = matrix[y][x];

        // right->left
        --y;
        --x;
        for ( ; x >= layer; --x) if (pos < result.size()) result[pos++] = matrix[y][x];

        //bottom->top
        ++x;
        --y;
        for ( ; y > layer; --y) if (pos < result.size()) result[pos++] = matrix[y][x];

        ++layer;
    }
    return result;
}

void test_spiralOrder()
{
    vector<vector<vector<int>>> tc = {{{1,2,3}, {4,5,6}, {7,8,9}},
            {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}},
            {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}}};
    vector<vector<int>> answers = {{1,2,3,6,9,8,7,4,5},
                                   {1,2,3,4,8,12,11,10,9,5,6,7},
                                   {1,2,3,6,9,12,11,10,7,4,5,8}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (spiralOrder(tc[i]) != answers[i]) ERROR_LOG;
    }
}
