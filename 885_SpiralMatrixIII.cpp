#include "Header.h"

// 885. Spiral Matrix III
// Level - Medium
// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
// Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.
// Now, we walk in a clockwise spiral shape to visit every position in this grid.
// Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)
// Eventually, we reach all R * C spaces of the grid.
// Return a list of coordinates representing the positions of the grid in the order they were visited.
// 
// Example 1:
// Input: R = 1, C = 4, r0 = 0, c0 = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
// 
// Example 2:
// Input: R = 5, C = 6, r0 = 1, c0 = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
// 
// Note:
// 1 <= R <= 100
// 1 <= C <= 100
// 0 <= r0 < R
// 0 <= c0 < C

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    int size = R * C;

    vector<vector<int>> result;
    result.push_back({r0, c0});
    int level = 1;
    int count = R * C - 1;

    auto countValid = [](int& r, int& c, int& R, int& C, int& count, vector<vector<int>>& res)
    {
        if (c < C && c >= 0 && r < R && r >= 0)
        {
            res.push_back({r, c});
            --count;
        }
    };

    int side = 0;
    ++c0;
    int mod, rem;
    while (count > 0)
    {
        side += 2;
        for (int i = 0; i < 4*side; ++i)
        {
            mod = i % side;
            rem = i / side;
            countValid(r0, c0, R, C, count, result);
            switch (rem)
            {
                case 0:
                    if (mod == side - 1) --c0;
                    else ++r0;
                    break;
                case 1:
                    if (mod == side - 1) --r0;
                    else --c0;
                    break;
                case 2:
                    if (mod == side - 1) ++c0;
                    else --r0;
                    break;
                default:
                    ++c0;
                    break;
            }
        }
    }
    return result;
}

void test_spiralMatrixIII()
{
    vector<vector<int>> tc = {{1,4,0,0}, {5,6,1,4}};
    vector<vector<vector<int>>> answers = {{{0,0}, {0,1}, {0,2}, {0,3}},
                                           {{1,4}, {1,5}, {2,5}, {2,4}, {2,3}, {1,3}, {0,3}, {0,4}, {0,5}, {3,5}, {3,4}, {3,3}, {3,2}, {2,2}, {1,2}, {0,2}, {4,5}, {4,4}, {4,3}, {4,2}, {4,1}, {3,1}, {2,1}, {1,1}, {0,1}, {4,0}, {3,0}, {2,0}, {1,0}, {0,0}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (spiralMatrixIII(tc[i][0], tc[i][1], tc[i][2], tc[i][3]) != answers[i]) ERROR_LOG;
    }
}
