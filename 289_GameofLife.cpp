#include "Header.h"

// 289. Game of Life
// Level - Medium
// 
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
// 
// Example 1:
// Input: board = [[0,1,0},{0,0,1},{1,1,1},{0,0,0]]
// Output: [[0,0,0},{1,0,1},{0,1,1},{0,1,0]]
// 
// Example 2:
// Input: board = [[1,1},{1,0]]
// Output: [[1,1},{1,1]]
// 
// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.
// 
// 
// Follow up:
// Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
// 

vector<int> dx8 = {1,1,0,-1,-1,-1,0,1};
vector<int> dy8 = {0,1,1,1,0,-1,-1,-1};

int GetNeighbourCount(int y, int x, vector<vector<int>>& board)
{
    int newX, newY;
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        newY = y + dy8[i];
        newX = x + dx8[i];
        if (newX < 0 || newY < 0 || newX >= board[0].size() || newY >= board.size()) continue;

        if (board[newY][newX] == 1) ++count;
    }
    return count;
}

void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> copy = board;

    int oneCount;
    for (int y = board.size()-1; y >= 0; --y)
    {
        for (int x = board[0].size() - 1; x >= 0; --x)
        {
            oneCount = GetNeighbourCount(y, x, copy);

            if (board[y][x] == 1 && (oneCount == 2 || oneCount == 3)) continue;
            if (board[y][x] == 0 && oneCount == 3) board[y][x] = 1;
            else board[y][x] = 0;
        }
    }
}

void test_gameOfLife()
{
    vector<VVI> tc = {{{0,1,0},{0,0,1},{1,1,1},{0,0,0}}, {{1,1},{1,0}}};
    vector<VVI> answers = {{{0,0,0},{1,0,1},{0,1,1},{0,1,0}}, {{1,1},{1,1}}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        gameOfLife(tc[i]);
        if (tc[i] != answers[i]) ERROR_LOG;
    }
}
