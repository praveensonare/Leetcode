#include "Utility.h"

// 334. Increasing Triplet Subsequence
// Level - Medium
// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
// 
// Example 1:
// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// 
// Example 2:
// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.
// 
// Example 3:
// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
// 
// Constraints:
// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 
// Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?

#if 0
// O(N) space approach.
bool increasingTriplet(vector<int>& nums) {
    int len = nums.size();
    vector<int> max_arr(len,nums[len-1]);
    vector<int> min_arr(len,nums[0]);

    for (int i = 1; i < len; ++i)
    {
        max_arr[len-i-1] = max(max_arr[len-i], nums[len-i]);
        min_arr[i] = min(min_arr[i-1], nums[i-1]);
    }

    for(int i = 1; i < len-1; ++i)
    {
        if (min_arr[i] < nums[i] && nums[i] < max_arr[i]) return true;
    }
    return false;
}
#else
bool increasingTriplet(vector<int>& nums) {
    int n1 = INT_MAX;
    int n2 = INT_MAX;
    for (auto n : nums)
    {
        if (n <= n1) n1 = n;
        else if(n <= n2) n2 = n;
        else return true;
    }
    return false;
}
#endif

void test_increasingTriplet()
{
    VVI tc = {{1,2,3,4,5},{5,4,3,2,1},{2,1,5,0,4,6}};
    vector<int> answers = {true, false, true};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (increasingTriplet(tc[i]) != answers[i]) ERROR_LOG;
    }
}

