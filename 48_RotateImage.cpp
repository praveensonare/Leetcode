#include "Utility.h"

// 48. Rotate Image
// Level - Medium
// 
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
// 
// Example 1:
// Input: matrix = {{1,2,3},{4,5,6},{7,8,9}}
// Output: {{7,4,1},{8,5,2},{9,6,3}}
// 
// Example 2:
// Input: matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
// Output: {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}
// 
// Example 3:
// Input: matrix = {{1}}
// Output: {{1}}
// 
// Example 4:
// Input: matrix = {{1,2},{3,4}}
// Output: {{3,1},{4,2}}
// 
// Constraints:
// matrix.length == n
// matrix[i].length == n
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

void rotate(vector<vector<int>>& matrix) {

    int len = matrix.size() - 1;
    int temp;
    for (int y = 0; y <= len/2; ++y)
    {
        for (int x = y; x < len - y; ++x)
        {
            temp = matrix[y][x];
            matrix[y][x] = matrix[len - x][y];
            matrix[len - x][y] = matrix[len - y][len - x];
            matrix[len - y][len - x] = matrix[x][len - y];
            matrix[x][len - y] = temp;
        }
    }
}

void test_rotate()
{
    vector<VVI> tc = {{{1,2,3},{4,5,6},{7,8,9}},
              {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}},
              {{1}},
              {{1,2},{3,4}}};

    vector<VVI> answers = {{{7,4,1},{8,5,2},{9,6,3}},
                   {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}},
                   {{1}},
                   {{3,1},{4,2}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        rotate(tc[i]);
        if (tc[i] != answers[i]) ERROR_LOG;
    }

}
