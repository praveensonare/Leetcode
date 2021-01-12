#include "Utility.h"

// 209. Minimum Size Subarray Sum
// Level - Medium
// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
// 
// Example:
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
// 
// Follow up:
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int len = nums.size();
        int minLen = INT_MAX;

        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];

            while (sum > s)
            {
                minLen = min(minLen, i - start + 1);
                sum -= nums[start++];
            }

            if (sum == s) minLen = min(minLen, i - start + 1);

        }

        return (INT_MAX == minLen) ? 0 : minLen;
    }

void test_minSubArrayLen()
{

}
