#include "Header.h"

// 1138. Alphabet Board Path
// Level - Medium
// 
// On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.
// 
// We may make the following moves:
// 'U' moves our position up one row, if the position exists on the board;
// 'D' moves our position down one row, if the position exists on the board;
// 'L' moves our position left one column, if the position exists on the board;
// 'R' moves our position right one column, if the position exists on the board;
// '!' adds the character board[r][c] at our current position (r, c) to the answer.
// (Here, the only positions that exist on the board are positions with letters on them.)
// Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.
// 
// Example 1:
// Input: target = "leet"
// Output: "DDR!UURRR!!DDD!"
// 
// Example 2:
// Input: target = "code"
// Output: "RR!DDRR!UUL!R!"
// 
// Constraints:
// 1 <= target.length <= 100
// target consists only of English lowercase letters.

string alphabetBoardPath(string target) {
    unordered_map<char, pair<int,int>> H; // char-><r,c>
    for (int i = 0; i < 26; ++i) H['a'+ i] = pair<int,int>(i/5, i%5);

    pair<int,int> pos = pair<int,int>(0,0);
    string result;
    for (const auto& c : target)
    {
        //cout << H[c].first<<","<< H[c].second << " pos:" << pos.first<<","<<pos.second << endl;
        //if (H[c] != pos)
        {
            // up
            if (H[c].first < pos.first) result += string(pos.first - H[c].first, 'U');

            // left
            if (H[c].second < pos.second) result += string(pos.second - H[c].second, 'L');

            // right
            if (H[c].second > pos.second) result += string(H[c].second - pos.second, 'R');

            // down
            if (H[c].first > pos.first) result += string(H[c].first - pos.first, 'D');
        }
        pos = H[c];
        result.push_back('!');

    }

    return result;
}

void test_alphabetBoardPath()
{
    VS tc = {"leet","code","zxa","hyz"};
    VS answers = {"RDD!UURRR!!DDD!","RR!RRDD!UUL!R!","DDDDD!URRR!UUUULLL!","RRD!RRDDD!LLLLD!"};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (alphabetBoardPath(tc[i]) != answers[i]) ERROR_LOG;
    }
}
