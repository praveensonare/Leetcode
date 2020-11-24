#include "Header.h"

// 55. Jump Game
// Level - Medium
// 
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
// 
// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
// 
// Constraints:
// 1 <= nums.length <= 3 * 10^4
// 0 <= nums[i][j] <= 10^5

bool canJump(vector<int>& nums) {
    int target = nums.size()-1;

    int max_reach = 0;
    for (int curr = 0; curr <= target; ++curr)
    {
        max_reach = max(curr + nums[curr], max_reach);
        if (target <= max_reach) return true;
        else if ((curr == max_reach)) return false;
    }
    return false;
}

void test_canJump()
{
    vector<vector<int>> tc = {{2,3,1,1,4}, {3,2,1,0,4}};
    vector<bool> answers = {true, false};
    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (canJump(tc[i]) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
