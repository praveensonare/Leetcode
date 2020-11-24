#include "Header.h"

// 198. House Robber
// Level -Easy
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// 
// Example 1:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
// Example 2:
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.
// 
// Constraints:
// 0 <= nums.length <= 100
// 0 <= nums[i] <= 400


int rob(vector<int>& nums) {
        int t1 = 0, t2 = 0;

        int temp;
        for (auto n : nums)
        {
            temp = t2;
            t2 = max(t1 + n, t2);
            t1 = temp;
        }
        return t2;
    }

void test_rob()
{
    vector<vector<int>> tc = {{1,2,3,1}, {2,7,9,3,1}};
    vector<int> answers = {4, 12};

    for (unsigned i = 0; i < tc.size(); ++i)
    {
        if (rob(tc[i]) != answers[i]) cout << __FUNCTION__ <<"+"<< __LINE__ << " Test_" << i << "=>FAILED"<< endl;
    }
}
