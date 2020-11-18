#include "Header.h"

// 200. Number of Islands
// Level - Medium
//
// Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// 
// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
//
// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
//  
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.
// 

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
void dfs(vector<vector<char>>& grid, int x, int y)
{
	if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return;
	if (grid[y][x] == '0') return;
	grid[y][x] = '0';
	for (int i = 0; i < 4; ++i)
	{
		dfs(grid, x + dx[i], y + dy[i]);
	}
}

int numIslands(vector<vector<char>>& grid) {
	int Y = grid.size();
	if (grid.empty()) return 0;

	int X = grid[0].size();
	int island = 0;
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (grid[y][x] == '1')
			{
				++island;
				dfs(grid, x, y);
			}
		}
	}
	return island;
}


void test_numIslands()
{
    vector<vector<vector<char>>> tc = { {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}},
                                        {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}}
                                      };
    vector<int> answers = {1, 3};
    for (unsigned idx = 0; idx < tc.size(); ++idx)
    {
        if (numIslands(tc[idx]) != answers[idx]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << idx << "=>FAILED"<< endl;
    }
}

