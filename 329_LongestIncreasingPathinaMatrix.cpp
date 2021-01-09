#include "Utility.h"

// 329. Longest Increasing Path in a Matrix
// Level - Hard
// Given an m x n matrix, return the length of the longest increasing path in matrix.
// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
// 
// Example 1:
// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// 
// Example 2:
// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// 
// Example 3:
// Input: matrix = [[1]]
// Output: 1
// 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1


int dfsForLongestIncreasingPath(vector<vector<int>>& mat, int y, int x, int Y, int X, vector<vector<int>>& memo)
{
    if (memo[y][x] != 0) return memo[y][x];

    int ans = 1;
    int newX, newY;

    // move below 2 line out of function
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (newX < 0 || newX >= X || newY < 0 || newY >= Y || mat[newY][newX] <= mat[y][x]) continue;
        ans = max(ans, dfsForLongestIncreasingPath(mat, newY, newX, Y, X, memo)+1);

    }

    memo[y][x] = ans;
    return ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ans = 0;
    int Y = matrix.size();
    int X = matrix[0].size();

    vector<int> vx(X,0);
    vector<vector<int>> memo(Y, vx);

    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            memo[y][x] = dfsForLongestIncreasingPath(matrix, y, x, Y, X, memo);
            ans = max(memo[y][x], ans);
        }
    }

    return ans;
}

void test_longestIncreasingPath()
{
    vector<VVI> tc = {{{9,9,4},{6,6,8},{2,1,1}},
                      {{3,4,5},{3,2,6},{2,2,1}},
                      {{1}}};
    vector<int> answers = {4,4,1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (longestIncreasingPath(tc[i]) != answers[i]) ERROR_LOG;
    }
}
