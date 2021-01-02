#include "Utility.h"

// 1640. Check Array Formation Through Concatenation
// Level - Easy
// 
// You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
// Return true if it is possible to form the array arr from pieces. Otherwise, return false.
// 
// Example 1:
// Input: arr = [85], pieces = [[85]]
// Output: true
// 
// Example 2:
// Input: arr = [15,88], pieces = [[88],[15]]
// Output: true
// Explanation: Concatenate [15] then [88]
// 
// Example 3:
// Input: arr = [49,18,16], pieces = [[16,18,49]]
// Output: false
// Explanation: Even though the numbers match, we cannot reorder pieces[0].
// 
// Example 4:
// Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
// Output: true
// Explanation: Concatenate [91] then [4,64] then [78]
// 
// Example 5:
// Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
// Output: false
// 
// Constraints:
// 1 <= pieces.length <= arr.length <= 100
// sum(pieces[i].length) == arr.length
// 1 <= pieces[i].length <= arr.length
// 1 <= arr[i], pieces[i][j] <= 100
// The integers in arr are distinct.
// The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, vector<int>> H;
    for (auto p : pieces) H[p[0]] = p;

    int vIdx = 0;
    int pos = 0;

    for (auto n : arr)
    {
        if (vIdx == 0)
        {
            if (H.find(n) == H.end()) return false;

            if (H[n].size() > 1)
            {
                pos = 1;
                vIdx = n;
            }
        }
        else
        {
            if (H[vIdx][pos] != n) return false;
            ++pos;
            if (H[vIdx].size() == pos)
            {
                vIdx = 0;
                pos = 0;
            }
        }

    }
    return true;
}

void test_canFormArray()
{
    vector<pair<VI,VVI>> tc = {pair<VI,VVI>({85},{{85}}),
        pair<VI,VVI>({15,88},{{88},{15}}),
        pair<VI,VVI>({49,18,16},{{16,18,49}}),
        pair<VI,VVI>({91,4,64,78},{{78},{4,64},{91}}),
        pair<VI,VVI>({1,3,5,7},{{2,4,6,8}})};
    vector<bool> answer = {true,true,false,true,false};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (canFormArray(tc[i].first, tc[i].second) != answer[i]) ERROR_LOG;
    }
}
