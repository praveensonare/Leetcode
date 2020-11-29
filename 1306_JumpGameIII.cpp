#include "Header.h"

// 1306. Jump Game III
// Level - Medium
// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
// Notice that you can not jump outside of the array at any time.
// 
// Example 1:
// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation:
// All possible ways to reach at index 3 with value 0 are:
// index 5 -> index 4 -> index 1 -> index 3
// index 5 -> index 6 -> index 4 -> index 1 -> index 3
// 
// Example 2:
// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true
// Explanation:
// One possible way to reach at index 3 with value 0 is:
// index 0 -> index 4 -> index 1 -> index 3
// 
// Example 3:
// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.
// 
// Constraints:
// 1 <= arr.length <= 5 * 10^4
// 0 <= arr[i] < arr.length
// 0 <= start < arr.length


vector<bool> visit;

bool reach(vector<int>& arr, int start)
{
    if ( start < 0 || start >= arr.size()) return false;
    if (visit[start]) return false;
    if (arr[start] == 0) return true;

    visit[start] = true;
    return reach(arr, start - arr[start]) || reach(arr, start + arr[start]);

}


bool canReach(vector<int>& arr, int start) {
    int len = arr.size();
    visit = vector<bool>(arr.size(), false);

    return reach(arr, start);
}

void test_canReach()
{
    vector<pair<vector<int>, int>> tc = {pair<vector<int>,int>({4,2,3,0,3,1,2}, 5), pair<vector<int>,int>({4,2,3,0,3,1,2}, 0), pair<vector<int>,int>({3,0,2,1,2}, 2)};
    vector<bool> answers = {true, true, false};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (canReach(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
