#include "Utility.h"

// 1063. Number of Valid Subarrays
// Level - Hard
// 
// Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following condition:
// The leftmost element of the subarray is not larger than other elements in the subarray.
// 
// Example 1:
// Input: [1,4,2,5,3]
// Output: 11
// Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
// 
// Example 2:
// Input: [3,2,1]
// Output: 3
// Explanation: The 3 valid subarrays are: [3],[2],[1].
// 
// Example 3:
// Input: [2,2,2]
// Output: 6
// Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
// 
// 
// Note:
// 1 <= A.length <= 50000
// 0 <= A[i] <= 100000


int validSubarrays(vector<int>& nums) {
#if 1
    // solution 1 : largest area in histogram type, time and space  O(n)
    int len = nums.size();
    if (len == 0) return 0;

    stack<pair<int,int>> s; // val:pos
    nums.push_back(INT_MIN);

    pair<int,int> p(nums[0],0);
    s.push(p);
    int result = 0;

    for (int i = 1; i <= len; ++i)
    {
        p = s.top();
        if (nums[i] < p.first)
        {
            while(!s.empty() && s.top().first > nums[i])
            {
                result += (i - s.top().second);
                s.pop();
            }
        }
        s.push(pair<int,int>(nums[i],i));
    }
    return result;

#else

    // solution 2: optimized brute force time O(n^2) and space  O(n)
    int len = nums.size();
    vector<int> mins(len, nums[len-1]);

    int tmin = INT_MAX;
    for (int i = len - 1; i >= 0; --i)
    {
        tmin = min(tmin, nums[i]);
        mins[i] = tmin;
    }

    int result = 0;
    int j = 0;

    for (int i = 0; i < len; ++i)
    {
        if (nums[i] == mins[i])
        {
            result += (len - i);
        }
        else
        {
            j = i + 1;
            for ( ;j < len && nums[j] >= nums[i]; ++j);
            result += (j - i);
        }
    }
    return result;
#endif
}

void test_validSubarrays()
{

}
