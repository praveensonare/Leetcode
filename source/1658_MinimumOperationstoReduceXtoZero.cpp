#include "Utility.h"

// 1658. Minimum Operations to Reduce X to Zero
// Level - Medium
// 
// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.
// 
// Example 1:
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// 
// Example 2:
// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// 
// Example 3:
// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
// 
// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

int minOperations(vector<int>& nums, int x) {

        int total = 0;
        for (auto n : nums) total += n;

        if (x > total) return -1;

        int k = total - x;
        int maxsublen = -1;
        int s = 0;
        int len = nums.size();
        int start = 0;
        for (int i = 0; i < len; ++i)
        {
            s += nums[i];
            while (s > k)
            {
                s -= nums[start++];
            }

            if (s == k) maxsublen = max(maxsublen, i - start + 1);

        }

        return (maxsublen < 0) ? maxsublen : len - maxsublen;
    }

void test_minOperations()
{

}
