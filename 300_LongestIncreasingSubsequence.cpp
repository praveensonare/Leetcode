#include "Utility.h"

// 300. Longest Increasing Subsequence
// Level - Medium
// 
// Given an integer array nums, return the length of the longest strictly increasing subsequence.
// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
// 
// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// 
// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4
// 
// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
// 
// Constraints:
// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
// 
// Follow up:
// Could you come up with the O(n2) solution?
// Could you improve it to O(n log(n)) time complexity?


int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(nums.size(), 1);
    int maxSeqSize = 0;

    for (int i = len - 1; i >= 0; --i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (nums[j] > nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxSeqSize = max(maxSeqSize, dp[i]);
    }

    return maxSeqSize;
}

void test_lengthOfLIS()
{
    VVI tc = {{1,3,6,7,9,4,10,5,6}, {4,10,4,3,8,9}, {10,9,2,5,3,7,101,18}, {0,1,0,3,2,3}, {7,7,7,7,7,7,7}};
    VI answers = {6, 3, 4, 4, 1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (lengthOfLIS(tc[i]) != answers[i]) ERROR_LOG;
    }
}
