#include "Utility.h"

// 487. Max Consecutive Ones II
// Level - Medium
// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
// 
// Example 1:
// Input: [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
//     After flipping, the maximum number of consecutive 1s is 4.
// 
// Note:
// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000
// Follow up:
// What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
// 

int findMaxConsecutiveOnes(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) return len;
    int prevConsecutiveOnes = 0;
    int consecutiveOnes = 0;
    int maxOnes = 0;


    for(int i = 0; i < len; ++i)
    {
        if (nums[i] == 1)
        {
            if (i > 0 && nums[i] == nums[i-1])
                ++consecutiveOnes;
            else
            {
                consecutiveOnes = 1;
            }
        }
        else
        {
            maxOnes = max(maxOnes, prevConsecutiveOnes + consecutiveOnes + 1);
            prevConsecutiveOnes = consecutiveOnes;
            consecutiveOnes = 0;

        }
    }

    if (consecutiveOnes == len) return consecutiveOnes;
    return max(maxOnes, prevConsecutiveOnes + consecutiveOnes + 1);;
}

void test_findMaxConsecutiveOnes()
{
    vector<vector<int>> tc = {{1,0,1,1,0,1}, {0,0,1,1,0,1},{0},{1},{1,1},{0,0}};
    vector<int> answers = {4,4,1,1,2,1};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (findMaxConsecutiveOnes(tc[i]) != answers[i]) ERROR_LOG;
    }
}
