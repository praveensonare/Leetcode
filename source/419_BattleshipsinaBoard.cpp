#include "Header.h"

// 419. Battleships in a Board
// Level - Medium
// Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
// Example:
// X..X
// ...X
// ...X
// In the above board there are 2 battleships.
// Invalid Example:
// ...X
// XXXX
// ...X
// This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
// Follow up:
// Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?

int countBattleships(vector<vector<char>>& board) {
    if (board.empty()) return 0;

    int H = board.size();
    int W = board[0].size();
    int count = 0;

    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            if (board[h][w] == '.') continue;

            if ((w+1 == W || board[h][w+1] == '.') && (h+1 == H || board[h+1][w] == '.')) ++count;
        }
    }
    return count;
}

void test_countBattleships()
{
    vector<vector<vector<char>>> tc = {{{'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'}}};
    VI answer = {2};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (countBattleships(tc[i]) != answer[i]) ERROR_LOG;
    }
}
