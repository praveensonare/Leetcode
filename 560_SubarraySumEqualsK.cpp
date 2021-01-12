#include "Utility.h"

// 560. Subarray Sum Equals K
// Level - Medium
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// 
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
// 
// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2
// 
// Constraints:
// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        M[0] = 1;
        int sum = 0;
        int temp = 0;
        int count = 0;
        for (auto n : nums)
        {
            sum += n;
            temp = sum - k;

            if (M.find(temp) != M.end()) count += M[temp];
            M[sum]++;
        }
        return count;
    }

void test_subarraySum()
{

}
