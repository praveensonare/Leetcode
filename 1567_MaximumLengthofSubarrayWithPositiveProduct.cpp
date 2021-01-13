#include "Utility.h"

// 1567. Maximum Length of Subarray With Positive Product
// Levl - Medium
// 
// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
// A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
// Return the maximum length of a subarray with positive product.
// 
// Example 1:
// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.
// 
// Example 2:
// Input: nums = [0,1,-2,-3,-4]
// Output: 3
// Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
// Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
// 
// Example 3:
// Input: nums = [-1,-2,-3,0,1]
// Output: 2
// Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
// 
// Example 4:
// Input: nums = [-1,2]
// Output: 1
// 
// Example 5:
// Input: nums = [1,2,3,5,-6,4,0,10]
// Output: 4
// 
// Constraints:
// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9

int getMaxLen(vector<int>& nums) {
    int maxLen = 0;
    int firstN = INT_MIN, lastN, start = 0;

    long prod = 1;
    nums.push_back(0);
    int len = nums.size();

    for (int i = 0; i < len; ++i)
    {
        if (nums[i] < 0)
        {
            if (firstN == INT_MIN) firstN = i;
            lastN = i;
            prod = -prod;
        }

        if (nums[i] == 0)
        {
            if (prod > 0)
            {
                maxLen = max(maxLen, i - start);
            }
            else
            {
                if (abs(firstN - start +1) < abs(abs(i - lastN)))
                    maxLen = max(maxLen, i - firstN - 1);
                else
                    maxLen = max(maxLen, lastN - start);
            }
            prod = 1;
            start = i + 1;
            firstN = INT_MIN;
        }

    }

    return maxLen;
}

void test_getMaxLen()
{
    VVI tc = {{1,-2,-3,4}, {0,1,-2,-3,-4},  {-1,-2,-3,0,1}, {-1,2}, {1,2,3,5,-6,4,0,10}, {-4,12,-35,0,5,-39,3,-25,-19,-12,23,-33,13,21,12,-25,15,9,38,-38}};
    VI answers = {4,3,2,1,4,15};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (answers[i] != getMaxLen(tc[i])) ERROR_LOG;
    }
}
