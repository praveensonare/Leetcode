#include "Header.h"

// 239. Sliding Window Maximum
// Level - Hard
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
// 
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
// 
// Example 3:
// Input: nums = [1,-1], k = 1
// Output: [1,-1]
// 
// Example 4:
// Input: nums = [9,11], k = 2
// Output: [11]
// 
// Example 5:
// Input: nums = [4,-2], k = 2
// Output: [4]
// 
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int len = nums.size();
    deque<pair<int, int>> dQ; // val, idx
    vector<int> result;

    for (int i = 0; i < len; ++i)
    {
        if (!dQ.empty() && dQ.front().second <= i - k) dQ.pop_front();
        while (!dQ.empty() && dQ.back().first <= nums[i])
        {
            dQ.pop_back();
        }
        dQ.push_back(pair<int, int>(nums[i], i));
        if (i >= k-1) result.push_back(dQ.front().first);
    }
    return result;
}

#define PAIR pair<vector<int>, int>
void test_maxSlidingWindow()
{
    vector<PAIR> tc = {PAIR({1,3,-1,-3,5,3,6,7}, 3), PAIR({1},1), PAIR({1,-1}, 1), PAIR({9,11},2), PAIR({4,-2},2)};
    vector<vector<int>> answers = {{3,3,5,5,6,7}, {1}, {1,-1}, {11}, {4}};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (maxSlidingWindow(tc[i].first, tc[i].second) != answers[i]) ERROR_LOG;
    }
}
