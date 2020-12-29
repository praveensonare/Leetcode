#include "Header.h"

// 41. First Missing Positive
// Level - Hard
// Given an unsorted integer array nums, find the smallest missing positive integer.
// Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
// 
// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// 
// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// 
// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
// 
// Constraints:
// 0 <= nums.length <= 300
// -231 <= nums[i] <= 231 - 1

int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] <= 0) nums[i] = len+1;
    }

    int t;
    for (int i = 0; i < len; ++i)
    {
        t = abs(nums[i]);
        if (t > 0 && t <= len && nums[t-1] > 0) nums[t-1] = -nums[t-1];
    }

    for (int i = 0; i < len; ++i)
    {
        if (nums[i] >= 0) return i + 1;
    }
    return len + 1;

}

void test_firstMissingPositive()
{
    VVI tc = {{0,1,2}, {1,1}, {}, {5}, {1}, {1,2,3,4,5}, {1,2,0}, {3,4,-1,1}, {7,8,9,11,12}};
    VI answers = {3, 2, 1, 1, 2, 6, 3, 2, 1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (firstMissingPositive(tc[i]) != answers[i]) ERROR_LOG;
    }
}
