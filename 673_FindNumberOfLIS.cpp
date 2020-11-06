#include "Header.h"

// 673
#if 0
673. Number of Longest Increasing Subsequence
Given an integer array nums, return the number of longest increasing subsequences.

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Constraints:

0 <= nums.length <= 2000
-106 <= nums[i] <= 106

#endif

int findNumberOfLIS(vector<int>& nums) {
    int mx = 0;
    int len = nums.size();
    int count = len;
    vector<int> val(len, 1);
    //vector<int> count(len, 0);

    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (nums[j] > nums[i])
            {
                val[j] = val[i] + 1;
                if (val[j] == mx)
                    ++count;
                else if (val[j] > mx)
                {
                    count = 1;
                    mx = val[j];
                }
            }
        }
    }

    return count;
}

