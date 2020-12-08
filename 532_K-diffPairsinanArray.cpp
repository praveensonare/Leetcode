#include "Header.h"

// 532. K-diff Pairs in an Array
// Level - Medium
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
// 
// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
// 
// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.
// 
// Example 1:
// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// 
// Example 2:
// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// 
// Example 3:
// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).
// 
// Example 4:
// Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
// Output: 2
// 
// Example 5:
// Input: nums = [-1,-2,-3], k = 1
// Output: 2
// 
// Constraints:
// 1 <= nums.length <= 104
// -107 <= nums[i] <= 107
// 0 <= k <= 107

int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;

    set<pair<int,int>> H;
    unordered_set<int> S;

    for (auto n : nums)
    {
        if (S.find(n-k) != S.end()) H.insert(pair<int,int>(min(n-k, n), max(n-k, n)));
        if (S.find(n+k) != S.end()) H.insert(pair<int,int>(min(n+k, n), max(n+k, n)));
        S.insert(n);
    }
    return H.size();
}
#define PAIR pair<vector<int>,int>
void test_findPairs()
{
    vector<pair<vector<int>, int>> tc = { PAIR({3,1,4,1,5}, 2), PAIR({1,2,3,4,5},1), PAIR({1,3,1,5,4},0), PAIR({1,2,4,4,3,3,0,9,2,3},3), PAIR({-1,-2,-3},1)};
    vector<int> answer = {2, 4, 1, 2, 2};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findPairs(tc[i].first, tc[i].second) != answer[i]) ERROR_LOG;
    }
}
